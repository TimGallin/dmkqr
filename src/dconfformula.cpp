#include "dmkqr.h"
#include "dconfformula.h"
#include "dconfpreset.h"

#include "implfunc/explconstant.h"
#include "implfunc/implrsa.h"

using namespace tinyxml2;
using namespace std;

DconfFormula::DconfFormula(){

}

DconfFormula::~DconfFormula(){

}

int DconfFormula::Initial(tinyxml2::XMLElement *pFormulaEle){
    if(pFormulaEle == NULL){
        return DMKQR_FAILED;
    }


    return DMKQR_SUCCESS;
}



/*
 *Parse formula
 */
int DconfFormula::Parse(const char* pFormula, FormulaExe* pParent){
    if(pFormula == NULL){
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

    const char* pRecord = pFormula;
    const char* p = pRecord;
    char ch = *p;

    while(ch != '\0'){
        switch(state){
            case sw_loop:
                if(ch == '('){
                    state = sw_parenthesis_open;
                }
                else if(ch == '.'){
                    state = sw_dot;
                }else if(ch == '$'){
                    state = sw_variable;
                }
                else if(ch == ')'){
                    state = sw_parenthesis_close;
                }

                state = sw_const;
                break;
            //Implicit variable.timestamp etc.
            case sw_dot:
                if(dmkqr_str2_cmp(p,'_','f','')){
                    state = sw_dot_func;
                }else if(dmkqr_str2_cmp(p,'_','$','')){
                    state = sw_dot_var;
                }else{
                    return DMKQR_PARSE_ERROR;
                }
                p+=1;
                pRecord = p;

            case sw_dot_func:
                if((ch > 'Z' || ch < 'A') && (ch <'0' || ch>'9')){
                    return DMKQR_PARSE_ERROR;
                }
                
                if(ch == '('){
                    pParent->pushback(FormulaFactory(pRecord));
                    state = sw_parenthesis_open;
                }
            
            case sw_parenthesis_open:
                Parse(p+1, pParent->LastFormula());
            case sw_parenthesis_close:
                break;
            default:
                break;

        ++p;

        }
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
        return(new ImplRSA);
    }
    else if(dmkqr_str3_cmp(pFormula,'D','E','S')){
        return(new ImplRSA);
    }
    else if(dmkqr_str3_cmp(pFormula,'A','E','S')){
        return(new ImplRSA);
    }

    return NULL;
}
