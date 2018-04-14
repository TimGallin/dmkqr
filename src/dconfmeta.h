#ifndef DMKQR_HEADER_DMKCONFOBJ
#define DMKQR_HEADER_DMKCONFOBJ

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
	int SetImplPreset(DconfPreset* pPreset);

	DconfPreset* GetImplPreset();
	
private:
	std::string _sName;
	DconfPreset* _pPreset;
};

#endif
