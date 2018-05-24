#include "dmkqr.h"
#include "dconfmgr.h"

#include "tinyxml2/tinyxml2.h"



using namespace std;
using namespace tinyxml2;

DconfManager::DconfManager():_pFirstScheme(NULL)
{
}

DconfManager::~DconfManager()
{
}

/*
 * Load config file.
 */
int DconfManager::Load(const char *file){
    FILE* pFile = fopen(file, "rb");
    if(pFile == NULL){
        return -1;
    }

	tinyxml2::XMLDocument doc;
    XMLError xmlerr;
    xmlerr = doc.LoadFile(pFile);
	
    if(xmlerr != XML_SUCCESS){
        return -1;
    }

    XMLElement* pPresetEle = doc.FirstChildElement(XML_ROOT)->FirstChildElement(XML_IMPLICIT_PRESET);
    DconfPreset* pPreset = pPresetEle == NULL ? NULL : new DconfPreset(pPresetEle);

    XMLElement* pSchemeEle = doc.FirstChildElement(XML_ROOT)->FirstChildElement(XML_SCHEME);

    DconfScheme* pTransitScheme = NULL;

    while(pSchemeEle){
        DconfScheme* pScheme = new DconfScheme();
        pScheme->SetImplPreset(pPreset);
        pScheme->Initial(pSchemeEle);

        if(pTransitScheme != NULL){
            pTransitScheme->SetSibling(pScheme);
        }

        if(_pFirstScheme == NULL){
            _pFirstScheme = pScheme;
        }

        pTransitScheme = pScheme;

        pSchemeEle = pSchemeEle->NextSiblingElement("scheme");
    }

	return 0;
}


/*
 * Run scheme formula via name.
 */
std::string DconfManager::RunScheme(const char* pName){
    if(_pFirstScheme == NULL){
        return "";
    }

    DconfScheme* pTarget = NULL;
    pTarget = _pFirstScheme;
    while(pTarget){
        if(strcmp(pTarget->GetName(), pName) == 0){
            break;
        }

        pTarget = pTarget->GetSibling();
    }

    if(pTarget == NULL){
        return "";
    }

    return pTarget->Run();
}