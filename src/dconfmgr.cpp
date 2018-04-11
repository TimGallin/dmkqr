#include "dmkqr.h"
#include "dconfmgr.h"

#include "tinyxml2/tinyxml2.h"

using namespace std;
using namespace tinyxml2;

DconfManager::DconfManager()
{
}

DconfManager::~DconfManager()
{
}

/*
 * Load config file.
 */
int DconfManager::Load(const char *file){
    FILE* pFile = fopen(file, "r");
    if(pFile == NULL){
        return -1;
    }

    XMLDocument doc;
    XMLError xmlerr;
    xmlerr = doc.LoadFile(pFile);

    if(xmlerr != XML_SUCCESS){
        return -1;
    }

    XMLElement* pEle = NULL;

    pEle = doc.FirstChildElement("conf")->FirstChildElement("scheme");

}