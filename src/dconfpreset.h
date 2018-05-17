#ifndef DMKQR_HEADER_DCONFPRESET
#define DMKQR_HEADER_DCONFPRESET


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
     *Extrac information from xml node.
     */
    int Initial(tinyxml2::XMLElement *pPresetElement);


    /*
     *Set preset vars.
     */
    void InitVars(tinyxml2::XMLElement *pPresetElement);

	/*
	Access vector preset.
	*/
	std::vector<std::string>& GetPresetVars();

private:
    std::string _sRsaPub;
    std::string _sRsaPri;
    std::string _sAesKey;
    std::string _sDesKey;

    std::vector<std::string> _vecVars;
};

#endif