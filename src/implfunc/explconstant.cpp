#include "../dmkqr.h"
#include "explconstant.h"

ExplConstan::ExplConstan(){

}

ExplConstan::~ExplConstan(){

}

std::string ExplConstan::Run(){
    return _sValue;
}

void ExplConstan::SetValue(const std::string& sValue){
    _sValue = sValue;
}

std::string ExplConstan::GetFormulaName(){
	return "";
}