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

    /*
     *Set&Get Next Sibling scheme.
     */
    void SetSibling(DconfScheme* pNext);

    DconfScheme* GetSibling();

    /*
     *Get variable's value via its name.
     */
    std::string GetVarsValue(const char* pName);
private:
    std::string _sFormula;
    DconfVar* _pFirstVar;

    DconfScheme* _pNextScheme;
};

#endif