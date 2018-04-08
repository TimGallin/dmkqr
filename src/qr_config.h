#ifndef DMKQR_QRCONFIG_HEAD
#define DMKQR_QRCONFIG_HEAD

class DmkqConfig{
    DmkqConfig();
    ~DmkqConfig();

    /*
     *Description
     *		Load config file.
     */
    int LoadConfig(const char* pConfFile);

};

#endif
