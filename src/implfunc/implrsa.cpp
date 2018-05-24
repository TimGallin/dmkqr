#include "../dmkqr.h"
#include "implrsa.h"

#include <crypto\rng.h>
#include <crypto\rsa.h>
#include <crypto\files.h>
#include <crypto\osrng.h>
#include <crypto\base64.h>
using namespace std;

static string PRI_HEADER = "-----BEGIN RSA PRIVATE KEY-----";
static string PRI_FOOTER = "-----END RSA PRIVATE KEY-----";

static string PUB_HEADER = "-----BEGIN PUBLIC KEY-----";
static string PUB_FOOTER = "-----END PUBLIC KEY-----";

ImplRSA::ImplRSA(const std::string& fPubKey, const std::string& fPriKey){
	SetPubKey(fPubKey);
	SetPriKey(fPriKey);
}

ImplRSA::~ImplRSA(){

}

string ImplRSA::Run(){
    string sPlain = RunSubs();
	string sCipher = "";

	//Do encrypt here.
	size_t pos1, pos2;
	pos1 = _sPrikey.find(PRI_HEADER);
	if (pos1 == string::npos) {
		DMKQRMSG(L"Invalid RSA cert.");
		return "error";
	}

	pos2 = _sPrikey.find(PRI_FOOTER, pos1 + 1);
	if (pos2 == string::npos){
		DMKQRMSG(L"Invalid RSA cert.");
		return "error";
	}
	// Start position and length
	pos1 = pos1 + PRI_HEADER.length();
	pos2 = pos2 - pos1;
	string keystr = _sPrikey.substr(pos1, pos2);

	// Base64 decode, place in a ByteQueue    
	CryptoPP::ByteQueue queue;
	CryptoPP::Base64Decoder decoder;

	decoder.Attach(new CryptoPP::Redirector(queue));
	decoder.Put((const CryptoPP::byte*)keystr.data(), keystr.length());
	decoder.MessageEnd();

#ifdef DEBUG

	// Write to file for inspection
	CryptoPP::FileSink fs("decoded-key.der");
	queue.CopyTo(fs);
	fs.MessageEnd();

#endif // DEBUG



    //Do rsa encrypt
	try{

		string RSA_PRIV_KEY;
		CryptoPP::RSA::PrivateKey  rsaPri;
		rsaPri.BERDecodePrivateKey(queue, false /*paramsPresent*/, queue.MaxRetrievable());

		// BERDecodePrivateKey is a void function. Here's the only check
		// we have regarding the DER bytes consumed.
		_ASSERT(queue.IsEmpty());

		CryptoPP::AutoSeededRandomPool prng;
		bool valid = rsaPri.Validate(prng, 3);
		if (!valid){
			cerr << "RSA private key is not valid" << endl;
			_ASSERT("RSA private key is not valid");
		}
			

		CryptoPP::RSAES_PKCS1v15_Encryptor rpe(rsaPri);
		CryptoPP::StringSource ss1(sPlain, true, new CryptoPP::PK_EncryptorFilter(prng, rpe, new CryptoPP::StringSink(sCipher))); // StringSource
		
	}
	catch (const CryptoPP::Exception& ex){
		cerr << ex.what() << endl;
	}

	return sCipher;
}

void ImplRSA::SetPubKey(const string& sCertFile){
	ReadCert(_sPubkey, sCertFile);
}

void ImplRSA::SetPriKey(const std::string& sCertFile){
	ReadCert(_sPrikey, sCertFile);
}

std::string ImplRSA::GetFormulaName(){
	return FORMULA_EXECUTER_RSA;
}


void ImplRSA::ReadCert(std::string& sCert, const std::string& sFile){
	FILE* pFile = NULL;
	int nOpen = fopen_s(&pFile, sFile.c_str(), "r");
	if (nOpen != 0){
		return;
	}

	fseek(pFile, 0, SEEK_END);
	int nSize = ftell(pFile);
	sCert.resize(nSize);
	fseek(pFile, 0, SEEK_SET);

	nOpen = fread_s((char*)sCert.c_str(), nSize, sizeof(char), nSize, pFile);

	fclose(pFile);
}