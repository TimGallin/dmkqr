#include "../dmkqr.h"
#include "ExplConstant.h"

ExplConstant::ExplConstant(){

}

ExplConstant::ExplConstant(const std::string& sValue) :_sValue(sValue) {

}

ExplConstant::~ExplConstant(){

}

std::string ExplConstant::Run(){
    return _sValue;
}

void ExplConstant::SetValue(const std::string& sValue){
    _sValue = sValue;
}

std::string ExplConstant::GetFormulaName(){
	return _sValue;
}