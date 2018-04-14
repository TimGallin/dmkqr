#include "dmkqr.h"

#include "dconfpreset.h"
#include "dconfscheme.h"

using namespace std;
using namespace tinyxml2;

DconfScheme::DconfScheme(){

}

DconfScheme::~DconfScheme(){
}

/*
 *Initial shceme
 */
int DconfScheme::Initial(tinyxml2::XMLElement* pSchemeEle){
    if(pSchemeEle == NULL){
        return -1;
    }

    //Set name
    const char* pName = pSchemeEle->Attribute("name");
    pName = pName==NULL ? "nameshceme" : pName;
    SetName(pName);

    //Set impl-preset
    tinyxml2::XMLElement* pPreset = pSchemeEle->FirstChildElement("implicitpreset");
    if(pPreset != NULL){
        DconfPreset* pSchemeSet = new DconfPreset(pPreset);
        SetImplPreset(pSchemeSet);
    }

    
}

/*
 *
 */
std::string DconfScheme::Run(){

}