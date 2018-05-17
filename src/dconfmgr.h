#ifndef DMKQR_HEADER_DMKQRCONF
#define DMKQR_HEADER_DMKQRCONF

#include "dconfscheme.h"
#include "dconfpreset.h"

class DconfManager{
public:
	DconfManager();
	~DconfManager();

	/*
	 * Load config file.
	 */
	int Load(const char* file);


	/*
	 * Run scheme formula via name.
	 */
	std::string RunScheme(const char* pName);
private:
	DconfScheme* _pFirstScheme;
};

#endif
