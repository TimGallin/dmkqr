#include "dmkqr.h"
#include "dconfpreset.h"
#include "dconfvar.h"

DconfVar::DconfVar(){

}


DconfVarDconfVar(tinyxml2::XMLElement *pVariableEle){
    Initial(pVariableEle);
}


DconfVar::~DconfVar(){
    
}

/*
 * Get&Set value.
 */
const char* DconfVar::GetVal(){

}


void DconfVar::SetVal(const char *pVal){
    if(pVal == NULL){
        return;
    }

    if(strcmp(pVal, "editbox") == 0){
        _uiface = UiFace::ui_editbox;
    }
    else if(strcmp(pVal, "dropbox") == 0){
        _uiface = UiFace::ui_dropbox;
    }

    return;
}


/*
 * Get&set Ui
 */
void DconfVar::SetUi(const UiFace &ui){

}


UiFace DconfVar::GetUi(){
    return _uiface;
}

/*
 *Initial shceme variable
 */
int DconfVar::Initial(tinyxml2::XMLElement *pVariableEle){
    if(pVariableEle == NULL){
        return -1;
    }

    const char* pName = pVariableEle->Attribute("name");
    
}