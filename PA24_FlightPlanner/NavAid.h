#pragma once
#include <string>
#include <list>

class CWaypoint {
	/*
	ToDo:
		- overwork constructors: are all variables initialized?
		- 
	*/
	/*
	About CWaypoint:
		...
	*/
public:
	CWaypoint();
	CWaypoint(unsigned int uiAltitude, double dLongitude, double dLatitude, std::string strId);
	~CWaypoint();

	virtual unsigned int uiGetAltitude();
	virtual void setAltitude(unsigned int uiAltitude);
	virtual double dGetLatitude();
	virtual void setLatitude(double dLatitude);
	virtual double dGetLongitude();
	virtual void setLongitude(double dLongitude);
	virtual std::string strGetId();
	virtual void setId(std::string strId);
protected:
	unsigned int uiAltitude;
	double dLatitude;
	double dLongitude;
	std::string strId;
};

class CRadioStation : public CWaypoint {
	/*
	ToDo:
		- overwork constructors: are all variables initialized?
		- 
	*/
	/*
	About CRadioStation:
		...
	*/
public:
	CRadioStation();
	CRadioStation(unsigned int uiAltitude, double dLongitude, double dLatitude, std::string strId,
		float fFrequency, unsigned short usiType, std::string strName, unsigned short usiRange);
	~CRadioStation();

	float fGetFrequency();
	void setFrequency(float fFrequency);
	unsigned short usiGetType();
	void setType(unsigned short usiType);
	std::string strGetName();
	void setName(std::string strName);
	unsigned short usiGetRange();
	void setRange(unsigned short usiRange);
private:
	float fFrequency;
	unsigned short usiType; // bitwise: DME, VOR, NDB
	/*** bits and what they represent:
	0:NDB
	1:VOR
	2:DME
	*/
	std::string strName;
	unsigned short usiRange;
};

class CRunway {
	/*
	ToDo:
		- overwork constructors: are all variables initialized?
		- 
	*/
	/*
	About CRunway:
		...
	*/
public:
	CRunway();
	CRunway(unsigned int uiLength, unsigned int uiWidth, unsigned int uiMaxWeight, float fHeading, float fMaxTailwind, unsigned short usiSurfaceType);
	~CRunway();

	unsigned int uiGetLength();
	void setLength(unsigned int uiLength);
	unsigned int uiGetWidth();
	void setWidth(unsigned int uiWidth);
	unsigned int uiGetMaxWeight();
	void setMaxWeight(unsigned int uiMaxWeight);
	float fGetHeading();
	void setHeading(float fHeading);
	float fGetMaxTailwind();
	void setMaxTailwind(float fMaxTailwind);
	unsigned short usiGetSurfaceType();
	void setSurfaceType(unsigned short usiSurfaceType);
private:
	unsigned int uiLength;
	unsigned int uiWidth;
	unsigned int uiMaxWeight;
	float fHeading;
	float fMaxTailwind;
	unsigned short usiSurfaceType; // asphalt, concrete, gravel, sand, grass

		// might add additional or expand data: TORA, LDA, RVR, contamination etc. (to be extracted from METAR)
};

class CAirport : public CWaypoint {
	/*
	ToDo:
		- overwork constructors: are all variables initialized?
		- list: store pointer to list - not list itself
		- 
	*/
	/*
	About CAirport:
		...
	*/
public:
	CAirport();
	CAirport(unsigned int uiAltitude, double dLongitude, double dLatitude, std::string strId,
	std::string strName);
	~CAirport();

	std::string strGetName();
	void setName(std::string strName);
	std::string strGetMetar();
	void setMetar(std::string strMetar);
	std::string strGetTaf();
	void setTaf(std::string strTaf);

	std::list<CRunway*>* pGetRunwayList();

	CRunway* findRunway(/*acft weight, distance required, preferred surface type, etc.*/); // find most adequate runway
private:
	std::list<CRunway*> lRunways;

	std::string strName;
	std::string strMetar;
	std::string strTaf;
};