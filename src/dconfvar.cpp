#include "dmkqr.h"
#include "dconfpreset.h"
#include "dconfvar.h"

DconfVar::DconfVar():_pNext(NULL)
{
}

DconfVar::DconfVar(tinyxml2::XMLElement *pVariableEle):_pNext(NULL)
{
    Initial(pVariableEle);
}

DconfVar::~DconfVar()
{
}

/*
 * Get&Set value.
 */
const char *DconfVar::GetVal()
{
	return NULL;
}

void DconfVar::SetVal(const char *pVal)
{
    if (pVal == NULL)
    {
        return;
    }

    if (strcmp(pVal, "editbox") == 0)
    {
        _uiface = UiFace::ui_editbox;
    }
    else if (strcmp(pVal, "dropbox") == 0)
    {
        _uiface = UiFace::ui_dropbox;
    }

    return;
}

/*
 * Get&set Ui
 */
void DconfVar::SetUi(const UiFace &ui)
{
}

DconfVar::UiFace DconfVar::GetUi()
{
    return _uiface;
}

/*
 *Initial shceme variable
 */
int DconfVar::Initial(tinyxml2::XMLElement *pVariableEle)
{
    if (pVariableEle == NULL)
    {
        return DMKQR_FAILED;
    }

    const char *pName = pVariableEle->Attribute("name");
    if (pName != NULL)
    {
        SetName(pName);
    }

    tinyxml2::XMLElement *pPresetEle = pVariableEle->FirstChildElement("preset");
    if (pPresetEle == NULL)
    {
        return DMKQR_SUCCESS;
    }

    if (pPresetEle != NULL)
    {
        DconfPreset *pPresets = new DconfPreset();
        pPresets->InitVars(pPresetEle);
        SetImplPreset(pPresets);
    }

    return DMKQR_SUCCESS;
}

/*
 *Set&Get Sibling var.
 */
void DconfVar::SetSibling(DconfVar *pNext){
    _pNext = pNext;
}

DconfVar* DconfVar::GetSibling(){
    return _pNext;
}


std::string DconfVar::Run(){
	return "";
}