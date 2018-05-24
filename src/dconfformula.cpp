#include "dmkqr.h"
#include "dconfformula.h"
#include "dconfpreset.h"
#include "dconfscheme.h"
#include "implfunc/explconstant.h"
#include "implfunc/implrsa.h"
#include "implfunc\impltime.h"
#include "implfunc\implbase64.h"
using namespace tinyxml2;
using namespace std;

DconfFormula::DconfFormula(DconfMeta* pParent) :_pParent(pParent){

}

DconfFormula::~DconfFormula(){

}

int DconfFormula::Initial(tinyxml2::XMLElement *pFormulaEle){
    if(pFormulaEle == NULL){
        return DMKQR_FAILED;
    }
	const char* pStart = pFormulaEle->GetText();
    return Parse(pStart, this);
}



/*
 *Parse formula
 */
int DconfFormula::Parse(const char* &p, FormulaExe* pParent){
    if(p == NULL){
        return DMKQR_FAILED;
    }

    enum{
        sw_loop,
        sw_const,
        sw_dot,
        sw_dot_func,
        sw_dot_var,
        sw_variable,
        sw_function,
        sw_parenthesis_open,
        sw_parenthesis_close,
        sw_plus,
        sw_space
    } state = sw_loop;

    const char* pRecord = p;

    char ch = *p;


    while(ch != '\0'){
        switch(state){
            case sw_loop:
                if(ch == '('){
                    state = sw_parenthesis_open;
					break;
                }
                else if(ch == '.'){
                    state = sw_dot;
					break;
                }else if(ch == '$'){
                    state = sw_variable;
					break;
                }
                else if(ch == ')'){
                    state = sw_parenthesis_close;
					break;
                }
				else if (ch == '+'){
					state = sw_loop;
					break;
				}
				else if (ch == '\'') {
					state = sw_const;
					break;
				}

				state = sw_loop;
                break;
            //Implicit variable.timestamp etc.
            case sw_dot:
				if (dmkqr_str2_cmp(p, 'f', '_', '')){
					++p;
                    state = sw_dot_func;
					break;
				}
				else if (dmkqr_str2_cmp(p, '$', '_', '')){
					++p;
                    state = sw_dot_var;
					break;
                }else{
                    return DMKQR_PARSE_ERROR;
                }
                p+=1;
                pRecord = p;

			case sw_dot_func:{
				if ((ch > 'Z' || ch < 'A') && (ch <'0' || ch>'9')){
					return DMKQR_PARSE_ERROR;
				}

				FormulaExe* pFormula = FormulaFactory(p);
				pParent->pushback(pFormula);
				p += pFormula->GetFormulaName().length();

				if (*p == '('){
					state = sw_parenthesis_open;
				}
				break;
			}

			case sw_dot_var:{
				if ((ch > 'Z' || ch < 'A') && (ch <'0' || ch>'9') && (ch <'a' || ch>'z')){
					return DMKQR_PARSE_ERROR;
				}

				FormulaExe* pFormula = DotVarFactory(p);
				pParent->pushback(pFormula);
				p += pFormula->GetFormulaName().length();

				state = sw_loop;

				break;
			}
                
			case sw_const: {
				FormulaExe* pFormula = ConstFactory(p);
				pParent->pushback(pFormula);
				p += pFormula->GetFormulaName().length();//Ignore  the single quote of the tail.

				state = sw_loop;
				break;
			}

			case sw_parenthesis_open:{
				if (Parse(p, pParent->LastFormula()) != DMKQR_SUCCESS){
					return DMKQR_FAILED;
				}

				break;
			}


                
            case sw_parenthesis_close:
                break;
            default:
                break;
        }
		if (*p == '\0') {
			break;
		}

		++p;
		ch = *p;
    }
    
    return DMKQR_SUCCESS;
}



std::string DconfFormula::Run(){
    return RunSubs();
}

FormulaExe* DconfFormula::FormulaFactory(const char *pFormula){
    if(pFormula == NULL){
        return NULL;
    }

    if(dmkqr_str3_cmp(pFormula,'R','S','A')){
		_ASSERT(GetImplPreset() != NULL);
		return(new ImplRSA(GetImplPreset()->GetRsaPubKey(), GetImplPreset()->GetRsaPriKey()));
    }
    else if(dmkqr_str3_cmp(pFormula,'D','E','S')){
		return NULL;
    }
    else if(dmkqr_str3_cmp(pFormula,'A','E','S')){
		return NULL;
    }
	else if (dmkqr_str4_cmp(pFormula, 'T', 'M', '1', '0')){
		return(new ImplTime(ImplTime::Precision::Seconds));
	}
	else if (dmkqr_str4_cmp(pFormula, 'T', 'M', '1', '3')){
		return(new ImplTime(ImplTime::Precision::MiliSeconds));
	}
	else if (dmkqr_str6_cmp(pFormula, 'B', 'a', 's', 'e', '6', '4')){
		return(new ImplBase64);
	}

    return NULL;
}


FormulaExe* DconfFormula::DotVarFactory(const char *pDotvar){
	DconfScheme* pParentScheme = static_cast<DconfScheme*>(_pParent);
	return pParentScheme->GetVariable(pDotvar);
}

FormulaExe* DconfFormula::ConstFactory(const char *pConst) {
	const char* pTail = strchr(pConst, '\'');
	string sValue(pConst, pTail);
	return new ExplConstant(sValue);
}