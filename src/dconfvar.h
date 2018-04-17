#ifndef DMKQR_HEADER_DCONFVAR
#define DMKQR_HEADER_DCONFVAR

#include "dconfmeta.h"
#include "implfunc/formulaexe.h"

class DconfVar : public DconfMeta, public FormulaExe::FormulaDelegate{
public:
	DconfVar();
	DconfVar(tinyxml2::XMLElement *pVariableEle);
	~DconfVar();

	virtual std::string Run() override;


	enum UiFace{
		ui_editbox=0,
		ui_dropbox
	};

	/*
	 * Get&Set value.
	 */
	const char* GetVal();

	void SetVal(const char* pVal);

	/*
	 * Get&set Ui
	 */
	void SetUi(const UiFace& ui);

	UiFace GetUi();


	/*
     *Initial shceme variable
     */
    int Initial(tinyxml2::XMLElement *pVariableEle);


	/*
	 *Set&Get Sibling var.
	 */
	void SetSibling(DconfVar* pNext);

	DconfVar* GetSibling();
private:
	UiFace _uiface;
	DconfVar* _pNext;
};

#endif
