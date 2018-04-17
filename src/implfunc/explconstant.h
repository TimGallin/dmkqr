#ifndef DMKQR_HEADER_IMPL_CONSTANT
#define DMKQR_HEADER_IMPL_CONSTANT

#include "formulaexe.h"

//Explicit constant
class ExplConstan : public FormulaExe{
public:
    ExplConstan();
    ~ExplConstan();

    virtual std::string Run() override;

    void SetValue(const std::string& sValue);
private:
    std::string _sValue;
};

#endif