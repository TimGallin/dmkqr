#include "../dmkqr.h"
#include "implbase64.h"

#include <crypto\base64.h>
#include <crypto\queue.h>
#include <crypto\files.h>
using namespace std;

ImplBase64::ImplBase64(){

}

ImplBase64::~ImplBase64(){

}

string ImplBase64::Run(){
    string sPlain = RunSubs();

	//Base64
	string sResult = "";

	CryptoPP::ByteQueue bq(2048);
	bq.Put2((const CryptoPP::byte*)sPlain.c_str(), sPlain.length(), 0, false);

	CryptoPP::Base64Encoder encoder;
	bq.CopyTo(encoder);
	encoder.MessageEnd();

	CryptoPP::word64 wSize = encoder.MaxRetrievable();
	if (wSize)
	{
		sResult.resize(wSize);
		encoder.Get((CryptoPP::byte*)sResult.data(), sResult.size());
	}

    return sResult;
}

std::string ImplBase64::GetFormulaName(){
	return "base64";
}

