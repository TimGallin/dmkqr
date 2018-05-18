#include "../dmkqr.h"
#include "impltime.h"

#include <time.h>

using namespace std;

ImplTime::ImplTime(const Precision& precision) :_precision(precision){

}

ImplTime::~ImplTime(){

}

string ImplTime::Run(){
    string sResult = "";

	time_t now;
	int unixTime = (int)time(&now);
	char tmp[512];
	memset(tmp, 0, 512);
	
	if (_precision == Precision::Seconds){
		sprintf_s(tmp, "%d", unixTime);
		sResult = tmp;
	}
	else if (_precision == Precision::Seconds){
		sprintf_s(tmp, "%d000", unixTime);
		sResult = tmp;
	}

    return sResult;
}



std::string ImplTime::GetFormulaName(){
	if (_precision == Precision::Seconds){
		return FORMULA_EXECUTER_TMSEC;
	}
	else if (_precision == Precision::Seconds){
		return FORMULA_EXECUTER_TMMILISEC;
	}
	return "";
}