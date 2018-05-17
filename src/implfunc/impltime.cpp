#include "../dmkqr.h"
#include "impltime.h"

using namespace std;

ImplTime::ImplTime(const Precision& precision) :_precision(precision){

}

ImplTime::~ImplTime(){

}

string ImplTime::Run(){
    string sResult = RunSubs();

    //Do rsa encrypt(sResult) ...

    return sResult;
}



std::string ImplTime::GetFormulaName(){
	if (_precision == Precision::Seconds){
		return "tmstamp10";
	}
	else if (_precision == Precision::Seconds){
		return "tmstamp13";
	}
	return "";
}