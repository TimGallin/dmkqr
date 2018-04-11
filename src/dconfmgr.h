#ifndef DMKQR_HEADER_DMKQRCONF
#define DMKQR_HEADER_DMKQRCONF

#include "dconfmeta.h"
class DconfManager : public DconfMeta{
public:
	DconfManager();
	~DconfManager();

	/*
	 * Load config file.
	 */
	int Load(const char* file);


	/*
	 * Get scheme via name.
	 */
	int GetScheme(const char* pName);
};

#endif
