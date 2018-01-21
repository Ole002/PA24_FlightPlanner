#pragma once
#include "AircraftData.h"
#include "NavAid.h"
#include "units.h"
#include <list>

class CRouteWeatherData {
	/*
	ToDo:
		- overwork constructors: are all variables initialized?
		- 
	*/
	/*
	About CRouteWeatherData:
		...
	*/
public:
	CRouteWeatherData();
	CRouteWeatherData(CLength* pFlightlevel, CVelocity* pWindSpeed, CAngle* pWindDirection, CTemperature* pOutsideAirTemp);
	~CRouteWeatherData();

	CLength* pGetFlightlevel();
	void setFlightlevel(CLength* pFlightlevel);
	CVelocity* pGetWindSpeed();
	void setWindSpeed(CVelocity* pWindSpeed);
	CAngle* pGetWindDirection();
	void setWindDirection(CAngle* pWindDirection);
	CTemperature* pGetOutsideAirTemp();
	void setOutsideAirTemp(CTemperature* pOutsideAirTemp);
private:
	CLength* pFlightlevel;
	CVelocity* pWindSpeed;
	CAngle* pWindDirection;
	CTemperature* pOutsideAirTemp;
};

class CGlobalRestrictions {
	/*
	ToDo:
		- overwork constructors: are all variables initialized?
		- 
	*/
	/*
	About CGlobalRestrictions:
		...
	*/
public:
	CGlobalRestrictions();
	CGlobalRestrictions(CLength* pMaxAlt, CLength* pMinAlt, CVolume* pFuelRemaining);
	~CGlobalRestrictions();

	CLength* pGetMaxAlt();
	void setMaxAlt(CLength* pMaxAlt);
	CLength* pGetMinAlt();
	void setMinAlt(CLength* pMinAlt);
	CVolume* pGetFuelRemaining();
	void setFuelRemaining(CVolume* pFuelRemaining);
private:
	CLength* pMaxAlt;
	CLength* pMinAlt;
	CVolume* pFuelRemaining;
};

class CLegRestriction {
	/*
	ToDo:
		- overwork constructors: are all variables initialized?
		- 
	*/
	/*
	About CLegRestriction:
		...
	*/
public:
	CLegRestriction();
	CLegRestriction(CLength* pMaxAlt, CLength* pMinAlt);
	~CLegRestriction();

	CLength* pGetMaxAlt();
	void setMaxAlt(CLength* pMaxAlt);
	CLength* pGetMinAlt();
	void setMinAlt(CLength* pMinAlt);
private:
	CLength* pMaxAlt;
	CLength* pMinAlt;
};

class CLeg {
	/*
	ToDo:
		- overwork constructors: are all variables initialized?
		- list: store pointer to list - not list itself
		- 
	*/
	/*
	About CLeg:
		...
	*/
public:
	CLeg();
	CLeg(CWaypoint* pDeparture, CWaypoint* pDestination, CLength* pDistance, CAngle* pTrack, CLength* pFlightlevel);
	~CLeg();

	CWaypoint* pGetDeparture();
	void setDeparture(CWaypoint* pWaypoint);
	CWaypoint* pGetDestination();
	void setDestination(CWaypoint* pWaypoint);
	CLength* pGetDistance();
	void setDistance(CLength* pDistance);
	CAngle* pGetTrack();
	void setTrack(CAngle* pTrack);
	CLength* pGetFlightlevel();
	void setFlightlevel(CLength* pFlightlevel);
	//add, remove, modify weather data
	std::list<CRouteWeatherData*>* pGetWeatherData();
	CLegRestriction* pGetLegRestriction();
	void setLegRestriction(CLegRestriction* pLegRestriction);
	CPerformanceData* pGetPerformanceData();
	void setPerformanceData(CPerformanceData* pPerformanceData);
private:
	CWaypoint* pDeparture;
	CWaypoint* pDestination;

	CLength* pDistance;
	CAngle* pTrack;
	CLength* pFlightlevel;
	std::list<CRouteWeatherData*> lWeatherData;
	CLegRestriction* pRestrictions; // optional - if null: use global values
	CPerformanceData* pLegPerformance; // optional - if null: use global values ;; if flightlevel differs from previous leg's flightlevel: Store altChangePerfData (irrelevant to this class; relevant to CRoute)
};

class CRoute {
	/*
	ToDo:
		- overwork constructors: are all variables initialized?
		- list: store pointer to list - not list itself
		- 
	*/
	/*
	About CRoute:
		...
	*/
public:
	CRoute();
	CRoute(CAirport* pDepartureAirport, CAirport* pDestinationAirport, CAircraftData* pAircraftData);
	~CRoute();

	CAirport* pGetDeparture();
	void setDeparture(CAirport* pDeparture);
	CAirport* pGetDestination();
	void setDestination(CAirport* pDestination);
	CAircraftData* pGetAircraftData();
	void setAircraftData(CAircraftData* pAircraftData);
private:
	CAirport* pDepartureAirport;
	CAirport* pDestinationAirport;
	CAircraftData* pAircraftData;
	
	std::list<CLeg*> lLegs;
	CGlobalRestrictions* pGlobalRestrictions;

	// how to do performance planning?
	// retrieve schedules from aircraft data?
	// save schedules per route (like it is done now)?
	// -> save pointer to aircraft data, where performance schedules are saved

	/*CAltChangePerfData** ppClimbPerformance; // list?!
	CPerformanceData* pCruisePerformance;
	CAltChangePerfData** ppDescentPerformance; // list?!*/

};


