#ifndef DMKQR_HEADER_DMKCONFOBJ
#define DMKQR_HEADER_DMKCONFOBJ

#include <string>

class DconfMeta{
public:
	DconfMeta();
	virtual	~DconfMeta();
	
	/*
	 * Get element's name.
	 */
	const char* GetName();

	void SetName(const char* pName);	


	/*
	 * Set implicit preset
	 */
	virtual int SetImpPreset();
	
private:
	std::string _sName;
};

#endif
