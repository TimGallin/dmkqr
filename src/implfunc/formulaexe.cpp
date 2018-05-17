#include "../dmkqr.h"
#include "formulaexe.h"

using namespace std;

FormulaExe::FormulaExe(){

}

FormulaExe::~FormulaExe(){

}

std::string FormulaExe::RunSubs(){
    string sResult = "";
    while(!_Subfuncs.empty()){
        sResult += _Subfuncs.front()->Run();
    }
	return sResult;
}

void FormulaExe::pushback(FormulaExe *pSunFunc){
    _Subfuncs.push(pSunFunc);
}

FormulaExe* FormulaExe::LastFormula() const{
    if(_Subfuncs.empty()){
        return NULL;
    }

    return _Subfuncs.back();
}


