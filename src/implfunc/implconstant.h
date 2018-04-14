#ifndef DMKQR_HEADER_IMPL_CONSTANT
#define DMKQR_HEADER_IMPL_CONSTANT

#include "implfunc.h"

class ImplConstan : public ImplFunc{
public:
    ImplConstan();
    ~ImplConstan();

    virtual std::string Run(const std::string& sSource);
};

#endif