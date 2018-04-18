#ifndef DMKQR_HEADER_IMPLFUNC
#define DMKQR_HEADER_IMPLFUNC

#include <string>
#include <queue>
class FormulaExe{
public:
    FormulaExe();
    
    /*
    *Every derived class implement this method.
    *The constant is also one of the ImplFuncs, its output is equal to input.
    */
    virtual std::string Run() = 0;

    std::string RunSubs();

    void pushback(FormulaExe* pSunFunc);

    FormulaExe* LastFormula() const;
protected:
   virtual ~FormulaExe();

private:
    std::queue<FormulaExe*> _Subfuncs;
    
};

#endif