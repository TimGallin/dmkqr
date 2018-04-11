#ifndef DMKQR_HEADER_DCONFSCHEME
#define DMKQR_HEADER_DCONFSCHEME

#include "dconfmeta.h"
#include <string>

class DconfScheme : public DconfMeta{
public:
    DconfScheme();
    ~DconfScheme();

    /*
     *
     */
    int Initial();


    /*
     *
     */
    std::string Run();
private:
    std::string _sFormula;
};

#endif