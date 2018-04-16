#ifndef DMKQR_HEADER_IMPL_CONSTANT
#define DMKQR_HEADER_IMPL_CONSTANT

#include "FormulaExe.h"

//Explicit constant
class ExplConstan : public FormulaExe, public FormulaExe::FormulaDelegate{
public:
    ExplConstan();
    ~ExplConstan();

    virtual std::string Run();

    void SetValue(const std::string& sValue);
private:
    std::string _sValue;
};

#endif