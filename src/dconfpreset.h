#ifndef DMKQR_HEADER_DCONFPRESET
#define DMKQR_HEADER_DCONFPRESET

#define MAX_VAR_PRESETS 5

class DconfPreset{
public:
    DconfPreset();
    DconfPreset(tinyxml2::XMLElement *pPresetElement);
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


    /*
     *Extrac information from xml node.
     */
    int Initial(tinyxml2::XMLElement *pPresetElement);

private:
    std::string _sRsaPub;
    std::string _sRsaPri;
    std::string _sAesKey;
    std::string _sDesKey;
};

#endif