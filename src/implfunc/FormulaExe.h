#ifndef DMKQR_HEADER_IMPLFUNC
#define DMKQR_HEADER_IMPLFUNC

#include <string>
#include <deque>
class FormulaExe{
public:
    FormulaExe();
    virtual ~FormulaExe();

    class FormulaDelegate{
         /*
         *Every derived class implement this method.
         *The constant is also one of the ImplFuncs, its output is equal to input.
         */
        virtual std::string Run() = 0;
    };
   


    void pushback(FormulaDelegate* pSunFunc);

    std::string RunSub();
private:
    std::deque<FormulaDelegate*> _Subfuncs;
    
};

#endif