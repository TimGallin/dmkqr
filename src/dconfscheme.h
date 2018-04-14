#ifndef DMKQR_HEADER_DCONFSCHEME
#define DMKQR_HEADER_DCONFSCHEME

#include "dconfmeta.h"
#include <string>

class DconfScheme : public DconfMeta{
public:
    DconfScheme();
    ~DconfScheme();

    /*
     *Initial shceme
     */
    int Initial(tinyxml2::XMLElement *pSchemeEle);


    /*
     *Run formula
     */
    std::string Run();
private:
    std::string _sFormula;
};

#endif