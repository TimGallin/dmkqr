#include "dmkqr.h"
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

}

/*
 *Get Ras private key
 */
std::string &DconfPreset::GetRsaPriKey(){

}

/*
 *Get AES encrypt key
 */
std::string &DconfPreset::GetAesKey(){

}

/*
 *Get DES encrypt key
 */
std::string &DconfPreset::GetDesKey(){

}

/*
 *Extrac information from xml node.
 */
int DconfPreset::Initial(tinyxml2::XMLElement *pPresetElement){
    if(pPresetElement == NULL){
        return -1;
    }

    auto valfilter = [](const char* x){
        return x == NULL ? "" : x;
    };

    _sRsaPub = valfilter(pPresetElement->Attribute(IMPL_PRESET_RASPUB));
    _sRsaPri = valfilter(pPresetElement->Attribute(IMPL_PRESET_RASPRI));
    _sAesKey = valfilter(pPresetElement->Attribute(IMPL_PRESET_AESKEY));
    _sDesKey = valfilter(pPresetElement->Attribute(IMPL_PRESET_DESKEY));
    
}