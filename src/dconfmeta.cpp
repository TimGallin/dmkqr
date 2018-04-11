#include "dmkqr.h"

#include "dconfpreset.h"
#include "dconfmeta.h"

DconfMeta::DconfMeta():_pPreset(NULL){

}

DconfMeta::~DconfMeta(){
    if(_pPreset != NULL){
        delete _pPreset;
    }
}

/*
 * Get element's name.
 */
const char* DconfMeta::GetName(){
    return _sName.c_str();
}


void DconfMeta::SetName(const char* pName){
    _sName = pName;
}

/*
 * Set implicit preset
 */
int DconfMeta::SetImplPreset(DconfPreset *pPreset){
    _pPreset = pPreset;
}
