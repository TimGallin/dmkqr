#include "../dmkqr.h"
#include "implrsa.h"

#include <crypto\rng.h>
#include <crypto\rsa.h>
#include <crypto\files.h>
#include <crypto\osrng.h>
using namespace std;

ImplRSA::ImplRSA(const std::string& fPubKey, const std::string& fPriKey) :_sPubkeyFile(fPubKey), _sPrikeyFile(fPriKey){

}

ImplRSA::~ImplRSA(){

}

string ImplRSA::Run(){
    string sPlain = RunSubs();
	sPlain = "ashflskdjfsdfiuoiwer-9438539045,test";
    //Do rsa encrypt(sResult) ...
	CryptoPP::RSA::PublicKey rsaPublic;
	CryptoPP::FileSource input2(_sPubkeyFile.c_str(), true);
	rsaPublic.BERDecode(input2);

	CryptoPP::RSA::PrivateKey rsaPrivate;
	CryptoPP::FileSource input(_sPrikeyFile.c_str(), true);
	rsaPrivate.BERDecode(input);

	string sCipher = "";
	CryptoPP::AutoSeededRandomPool rng;
	if (rsaPublic.Validate(rng, 3)){
		CryptoPP::RSAES_PKCS1v15_Encryptor rpe(rsaPublic);
		CryptoPP::StringSource ss1(sPlain, true, new CryptoPP::PK_EncryptorFilter(rng, rpe, new CryptoPP::StringSink(sCipher))); // StringSource
	}
	else if (rsaPrivate.Validate(rng, 3))
	{
		CryptoPP::RSAES_PKCS1v15_Encryptor rpe(rsaPrivate);
		CryptoPP::StringSource ss1(sPlain, true, new CryptoPP::PK_EncryptorFilter(rng, rpe, new CryptoPP::StringSink(sCipher))); // StringSource
	}
	else{
		throw runtime_error("Invalid rsa key.");
	}

	return sCipher;
}

void ImplRSA::SetPubKey(const string& sCertFile){
    _sPubkeyFile = sCertFile;
}

void ImplRSA::SetPriKey(const std::string& sCertFile){
    _sPrikeyFile = sCertFile;
}

std::string ImplRSA::GetFormulaName(){
	return FORMULA_EXECUTER_RSA;
}