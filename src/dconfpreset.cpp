#include "dmkqr.h"
#include "dconfmeta.h"
#include "dconfpreset.h"

using namespace std;
using namespace tinyxml2;

DconfPreset::DconfPreset(){

}

DconfPreset::DconfPreset(tinyxml2::XMLElement *pPresetElement){
    Initial(pPresetElement);
}

DconfPreset::~DconfPreset(){

}

/*
 *Get Ras public key
 */
std::string &DconfPreset::GetRsaPubKey(){
	return _sRsaPub;
}

/*
 *Get Ras private key
 */
std::string &DconfPreset::GetRsaPriKey(){
	return _sRsaPri;
}

/*
 *Get AES encrypt key
 */
std::string &DconfPreset::GetAesKey(){
	return _sAesKey;
}

/*
 *Get DES encrypt key
 */
std::string &DconfPreset::GetDesKey(){
	return _sDesKey;
}

/*
 *Extrac information from xml node.
 */
int DconfPreset::Initial(tinyxml2::XMLElement *pPresetElement){
    if(pPresetElement == NULL){
        return DMKQR_FAILED;
    }

    auto valfilter = [](const char* x){
        return x == NULL ? "" : x;
    };

    _sRsaPub = valfilter(pPresetElement->Attribute(IMPL_PRESET_RASPUB));
    _sRsaPri = valfilter(pPresetElement->Attribute(IMPL_PRESET_RASPRI));
    _sAesKey = valfilter(pPresetElement->Attribute(IMPL_PRESET_AESKEY));
    _sDesKey = valfilter(pPresetElement->Attribute(IMPL_PRESET_DESKEY));
    
    return DMKQR_SUCCESS;
}


/*
 *Set preset vars.
 */
void DconfPreset::InitVars(tinyxml2::XMLElement *pPresetElement){
    if(pPresetElement == NULL || strcmp(pPresetElement->Name(),XML_SCHEME_VAR_PRESET) != 0 ){
        return;
    }

    const char* pVariable = pPresetElement->GetText();

    if(pVariable != NULL){
        _vecVars.push_back(pVariable);
    }

    pPresetElement = pPresetElement->NextSiblingElement();
    if(pPresetElement == NULL){
        return;
    }

    InitVars(pPresetElement);
}


/*
Access vector preset.
*/
std::vector<std::string>& DconfPreset::GetPresetVars(){
	return _vecVars;
}