#ifndef DMKQR_HEADER_DCONFVAR
#define DMKQR_HEADER_DCONFVAR

#include "dconfmeta.h"

class DconfVar : public DconfMeta{
	DconfVar();
	~DconfVar();

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

private:
	UiFace _uiface;

};

#endif
