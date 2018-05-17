#include "../dmkqr.h"
#include "implrsa.h"

using namespace std;

ImplRSA::ImplRSA(){

}

ImplRSA::~ImplRSA(){

}

string ImplRSA::Run(){
    string sResult = RunSubs();

    //Do rsa encrypt(sResult) ...

    return sResult;
}

void ImplRSA::SetPubKey(const string& sCertFile){
    _sPubkeyFile = sCertFile;
}

void ImplRSA::SetPriKey(const std::string& sCertFile){
    _sPrikeyFile = sCertFile;
}

std::string ImplRSA::GetFormulaName(){
	return "RSA";
}