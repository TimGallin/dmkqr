#ifndef DMKQR_HEADER_DCONFVAR
#define DMKQR_HEADER_DCONFVAR

#include "dconfmeta.h"

#define MAX_VAR_PRESETS;

class DconfVar : public DconfMeta{
	DconfVar();
	~DconfVar();

	enum {
		ui_editbox=0,
		ui_dropbox
	}UiFace;

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
	 * Presets
	 */
	std::string PresetsVal[MAX_VAR_PRESETS];

private:
	UiFace _uiface;

};

#endif
