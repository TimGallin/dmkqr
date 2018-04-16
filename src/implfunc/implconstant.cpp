#include "../dmkqr.h"
#include "implconstant.h"

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