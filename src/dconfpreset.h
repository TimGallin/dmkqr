#ifndef DMKQR_HEADER_DCONFPRESET
#define DMKQR_HEADER_DCONFPRESET

#include "dconfmeta.h"

#define MAX_VAR_PRESETS 5

class DconfPreset : public DconfMeta{
public:
    DconfPreset();
    ~DconfPreset();

    /*
     *Get Ras public key
     */
    std::string& GetRsaPubKey();

    /*
     *Get Ras private key
     */
    std::string& GetRsaPriKey();


    /*
     *Get AES encrypt key
     */
    std::string& GetAesKey();


    /*
     *Get DES encrypt key
     */
    std::string& GetDesKey();

    /*
     *Presets value
     */
    std::string sVals[MAX_VAR_PRESETS];
};

#endif