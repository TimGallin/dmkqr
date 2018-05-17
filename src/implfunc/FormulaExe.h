#ifndef DMKQR_HEADER_IMPLFUNC
#define DMKQR_HEADER_IMPLFUNC

#include <string>
#include <queue>
class FormulaExe{
public:
    FormulaExe();
	virtual ~FormulaExe();
    
    virtual std::string Run() = 0;

	virtual std::string GetFormulaName() = 0;

    std::string RunSubs();

    void pushback(FormulaExe* pSunFunc);

    FormulaExe* LastFormula() const;

private:
    std::queue<FormulaExe*> _Subfuncs;
    
};

#endif