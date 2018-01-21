#pragma once

#include <list>
#include "units.h"

class CWeight {
	/*
	ToDo:
		- overwork constructors: are all variables initialized?
		- 
	*/
	/*
	About CWeight:
		total weight of aircraft consists of a number of mass points,
		which are represented by the class "CWeight".
		The class "CWeight" specifies the current weight and the location
		(LENGTH aft of datum) of its mass point. Furthermore it allows to
		store a type (types: see below) in order to categorize the mass points.
		Each mass point can be given a name in order to describe what the mass
		point does (e. g. seat front left, right wing fuel tank, ...)
	*/
public:
	CWeight();
	CWeight(CLength* pLocation, CMass* pMaxWeight);
	~CWeight();
	CMass* pGetMaxWeight();
	void setMaxWeight(CMass* pMaxWeight);
	CMass* pGetWeight();
	void setWeight(CMass* pWeight);
	CLength* pGetLocation();
	void setLocation(CLength* pLocation);
	unsigned short usiGetType();
	void setType(unsigned short usiType);
	std::string strGetName();
	void setName(std::string strName);

private:
	CMass* pMaxWeight;
	CMass* pWeight;
	CLength* pLocation;
	unsigned short usiType; 
	std::string strName;

// type of weight:
// when writing to file: "DryEmptyWeight", "Fuel", .. not case sensitive!
#define WeightType_Unspecified		0
#define WeightType_DryEmptyWeight	1
#define WeightType_Fuel				2
#define WeightType_Oil				3
#define WeightType_Seat				4
#define WeightType_CargoBaggage		5
};

class CPerformanceData {
	/*
	ToDo:
		- overwork constructors: are all variables initialized?
		- 
	*/
	/*
	About CPerformanceData:
		A flight plan consists of many sets of data, which represent the
		status of the aircraft at a specific time (time stamp) after engine
		start. The class "CPerformanceData" represents one set of data.
		The overall data (e.g. trip fuel, ...) is calculated by (in the case
		of trip fuel) "integrating" values over time.
		This class is somewhat similar to the class "CAircraftData". While this
		class represents one unique timespot during the flight, the class
		"CAircraftData" represents a 'static' status of the aircraft (most of its
		values remain constant during the flight).
		A CFlightStatus-object contains a list of CPerformanceData-objects. When
		the CFlightStatus object is deleted, the CPerformanceData-objects contained
		by the list are deleted as well.
	*/
public:
	CPerformanceData();
	CPerformanceData(CVelocity* fIas, CVolumeFlowRate* fFuelFlow);
	~CPerformanceData();

	virtual double dGetTimeStamp();
	virtual void setTimeStamp(double dTimeStamp);
	virtual CVelocity* pGetIas();
	virtual void setIas(CVelocity* pIas);
	virtual CVolumeFlowRate* pGetFuelFlow();
	virtual void setFuelFlow(CVolumeFlowRate* pFuelFlow);
	virtual CLength* pGetAltitude();
	virtual void setAltitude(CLength* pAltitude);
	
protected:
	double dTimeStamp; // timestamp: time after engine start (unit: seconds)
	CVelocity* pIas;
	CVolumeFlowRate* pFuelFlow;
	CLength* pAltitude;

	// add manifold pressure and rpm?!
};

class CAltChangePerfData : public CPerformanceData {
	// invoking constructor:
	// https://stackoverflow.com/questions/120876/what-are-the-rules-for-calling-the-superclass-constructor

	/*
	ToDo:
		- overwork constructors: are all variables initialized?
		- 
	*/
	/*
	About CAltChangePerfData
		Subclass of CPerformanceData; to be used when aircraft climbs or
		descents.
		Subsequently CAltChangePerfData features a range of altitudes.
	*/

public:
	CAltChangePerfData();
	CAltChangePerfData(CVelocity* pIas, CVolumeFlowRate* pFuelflow, CLength* uiAltBegin, CLength* uiAltEnd);
	~CAltChangePerfData();

	CLength* pGetAltBegin();
	void setAltBegin(CLength* uiAltBegin);
	CLength* pGetAltEnd();
	void setAltEnd(CLength* uiAltEnd);
private:
	CLength* pAltBegin;
	CLength* pAltEnd;
};

class CAircraftData {
	/*
	ToDo:
		- overwork constructors: are all variables initialized?
		- 
	*/
	/*
	About CAircraftData:
		The class CAircraftData represents the aircraft itself.
		It specifies the properties of the given aircraft at the beginning of the flight.
		In order to get the properties of the given aircraft during the flight, please
		refer to class "CFlightStatus".
		This class is somewhat similar to the class "CPerformanceData". While this
		class represents a 'static' status of the aircraft (most of the values
		remain constant during the flight), the class "CPerformanceData" represents
		one unique timespot during the flight.
	*/
public:
	CAircraftData();
	CAircraftData(CMass* pDryEmptyWeight, CMass* pOilWeight, CVelocity* pMaxCrosswind, std::string strRegistration);
	~CAircraftData();

	CVolume* pGetFuelCapacity();
	CMass* pGetWeight(); // returns total weight: dry empty weight + weight of all mass points
	CLength* pGetCg(); // total c.g. is determined by analysing all mass points.

	CMass* pGetDryEmptyWeight();
	void setDryEmptyWeight(CMass* pDryEmptyWeight);
	CMass* pGetOilWeight();
	void setOilWeight(CMass* pOilWeight);
	CVelocity* pGetMaxCrosswind();
	void setMaxCrosswind(CVelocity* pMaxCrosswind);
	std::string strGetRegistration();
	void setRegistration(std::string strRegistration);

private:
	CMass* pDryEmptyWeight;
	CMass* pOilWeight;
	std::list<CWeight*> lWeights;
	
	// more data: max. weights, cg limits, ...

	std::string strRegistration;
	/**
	cg and max weight:
	list of cg-weight-relations: minCg, maxCg, maxWeightAtMinCg, maxWeightAtmaxCg, maybe: "interpolation" (linear, ...)
	cgMin: lowest MinCg
	cgMax: highest maxCg
	**/

	CVelocity* pMaxCrosswind;

};

class CFlightStatus {
	/*
	ToDo:
		-
	*/
	/*
	About CFlightStatus:
		...
	*/
public:
	CFlightStatus();
	CFlightStatus(std::list<CPerformanceData*>* plPerformanceData);
	~CFlightStatus();

	void addCPerformanceDataObject(CPerformanceData* pPerformanceDataObject);
	CPerformanceData* getPerformanceData(double dTimeStamp);
	CFlightStatus* getFlightStatus(double dTimeStamp);
private:
	std::list<CPerformanceData*>* lPerformanceData;
};