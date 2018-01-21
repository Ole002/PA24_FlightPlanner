#include "Route.h"

CRouteWeatherData::CRouteWeatherData() {
	this->setFlightlevel(new CLength(0, Unit_Length_Flightlevel));
	this->setWindSpeed(new CVelocity(0, Unit_Velocity_MetersPerSecond));
	this->setWindDirection(new CAngle(0, Unit_Angle_Radiant));
	this->setOutsideAirTemp(new CTemperature(0, Unit_Temperature_Kelvin));
}
CRouteWeatherData::CRouteWeatherData(CLength* pFlightlevel, CVelocity* pWindSpeed, CAngle* pWindDirection, CTemperature* pOutsideAirTemp) {
	this->setFlightlevel(pFlightlevel);
	this->setWindSpeed(pWindSpeed);
	this->setWindDirection(pWindDirection);
	this->setOutsideAirTemp(pOutsideAirTemp);
}
CRouteWeatherData::~CRouteWeatherData() {
	delete this->pFlightlevel;
	delete this->pWindSpeed;
	delete this->pWindDirection;
	delete this->pOutsideAirTemp;
}
CLength* CRouteWeatherData::pGetFlightlevel() {
	return this->pFlightlevel;
}
void CRouteWeatherData::setFlightlevel(CLength* pFlightlevel) {
	if (this->pFlightlevel != pFlightlevel) {
		delete this->pFlightlevel;
	}
	this->pFlightlevel = pFlightlevel;
}
CVelocity* CRouteWeatherData::pGetWindSpeed() {
	return this->pWindSpeed;
}
void CRouteWeatherData::setWindSpeed(CVelocity* pWindSpeed) {
	if (this->pWindSpeed != pWindSpeed) {
		delete this->pWindSpeed;
	}
	this->pWindSpeed = pWindSpeed;
}
CAngle* CRouteWeatherData::pGetWindDirection() {
	return this->pWindDirection;
}
void CRouteWeatherData::setWindDirection(CAngle* pWindDirection) {
	if (this->pWindDirection != pWindDirection) {
		delete this->pWindDirection;
	}
	this->pWindDirection = pWindDirection;
}
CTemperature* CRouteWeatherData::pGetOutsideAirTemp() {
	return this->pOutsideAirTemp;
}
void CRouteWeatherData::setOutsideAirTemp(CTemperature* pOutsideAirTemp) {
	if (this->pOutsideAirTemp != pOutsideAirTemp) {
		delete this->pOutsideAirTemp;
	}
	this->pOutsideAirTemp = pOutsideAirTemp;
}

CGlobalRestrictions::CGlobalRestrictions() {
	this->setMinAlt(new CLength(0, Unit_Length_Meters));
	this->setMaxAlt(new CLength(0, Unit_Length_Meters));
	this->setFuelRemaining(new CVolume(0, Unit_Volume_CubicMeter));
}
CGlobalRestrictions::CGlobalRestrictions(CLength* pMaxAlt, CLength* pMinAlt, CVolume* pFuelRemaining) {
	this->setMaxAlt(pMaxAlt);
	this->setMinAlt(pMinAlt);
	this->setFuelRemaining(pFuelRemaining);
}
CGlobalRestrictions::~CGlobalRestrictions() {
	delete this->pMaxAlt;
	delete this->pMinAlt;
	delete this->pFuelRemaining;
}
CLength* CGlobalRestrictions::pGetMaxAlt() {
	return this->pMaxAlt;
}
void CGlobalRestrictions::setMaxAlt(CLength* pMaxAlt) {
	if (this->pMaxAlt != pMaxAlt) {
		delete this->pMaxAlt;
	}
	this->pMaxAlt = pMaxAlt;
}
CLength* CGlobalRestrictions::pGetMinAlt() {
	return this->pMinAlt;
}
void CGlobalRestrictions::setMinAlt(CLength* pMinAlt) {
	if (this->pMinAlt != pMinAlt) {
		delete this->pMinAlt;
	}
	this->pMinAlt = pMinAlt;
}
CVolume* CGlobalRestrictions::pGetFuelRemaining() {
	return this->pFuelRemaining;
}
void CGlobalRestrictions::setFuelRemaining(CVolume* pFuelRemaining){
	if (this->pFuelRemaining != pFuelRemaining) {
		delete this->pFuelRemaining;
	}
	this->pFuelRemaining = pFuelRemaining;
}

CLegRestriction::CLegRestriction() {
	this->setMaxAlt(new CLength(0, Unit_Length_Meters));
	this->setMinAlt(new CLength(0, Unit_Length_Meters));
}
CLegRestriction::CLegRestriction(CLength* pMaxAlt, CLength* pMinAlt){
	this->setMaxAlt(pMaxAlt);
	this->setMinAlt(pMinAlt);
}
CLegRestriction::~CLegRestriction() {
	delete this->pMaxAlt;
	delete this->pMinAlt;
}
CLength* CLegRestriction::pGetMaxAlt() {
	return this->pMaxAlt;
}
void CLegRestriction::setMaxAlt(CLength* pMaxAlt) {
	if (this->pMaxAlt != pMaxAlt) {
		delete this->pMaxAlt;
	}
	this->pMaxAlt = pMaxAlt;
}
CLength* CLegRestriction::pGetMinAlt() {
	return this->pMinAlt;
}
void CLegRestriction::setMinAlt(CLength* pMinAlt) {
	if (this->pMinAlt != pMinAlt) {
		delete this->pMinAlt;
	}
	this->pMinAlt = pMinAlt;
}

CLeg::CLeg() {
	this->pDeparture = NULL;
	this->pDestination = NULL;
	this->setDistance(new CLength(0, Unit_Length_Meters));
	this->setTrack(new CAngle(0, Unit_Angle_Radiant));
	this->setFlightlevel(new CLength(0, Unit_Length_Meters));
	this->pRestrictions = NULL;
	this->pLegPerformance = NULL;
}
CLeg::CLeg(CWaypoint* pDeparture, CWaypoint* pDestination, CLength* pDistance, CAngle* pTrack, CLength* pFlightlevel){
	this->setDeparture(pDeparture);
	this->setDestination(pDestination);
	this->setDistance(pDistance);
	this->setTrack(pTrack);
	this->setFlightlevel(pFlightlevel);
}
CLeg::~CLeg() {
	delete this->pDeparture;
	delete this->pDestination;
	delete this->pDistance;
	delete this->pTrack;
	delete this->pFlightlevel;

	// delete weather
	for (
		std::list<CRouteWeatherData*>::iterator lWeatherIter = lWeatherData.begin();
		lWeatherIter != lWeatherData.end();
		lWeatherIter++)
	{
		delete (*lWeatherIter);
	}

	delete this->pRestrictions;
	delete this->pLegPerformance;
}
CWaypoint* CLeg::pGetDeparture() {
	return this->pDeparture;
}
void CLeg::setDeparture(CWaypoint* pDeparture) {
	if (this->pDeparture != pDeparture) {
		delete this->pDeparture;
	}
	this->pDeparture = pDeparture;
}
CWaypoint* CLeg::pGetDestination() {
	return this->pDestination;
}
void CLeg::setDestination(CWaypoint* pDestination) {
	if (this->pDestination != pDestination) {
		delete this->pDestination;
	}
	this->pDestination = pDestination;
}
CLength* CLeg::pGetDistance() {
	return this->pDistance;
}
void CLeg::setDistance(CLength* pDistance) {
	if (this->pDistance != pDistance) {
		delete this->pDistance;
	}
	this->pDistance = pDistance;
}
CAngle* CLeg::pGetTrack() {
	return this->pTrack;
}
void CLeg::setTrack(CAngle* pTrack) {
	if (this->pTrack != pTrack) {
		delete this->pTrack;
	}
	this->pTrack = pTrack;
}
CLength* CLeg::pGetFlightlevel() {
	return this->pFlightlevel;
}
void CLeg::setFlightlevel(CLength* pFlightlevel) {
	if (this->pFlightlevel != pFlightlevel) {
		delete this->pFlightlevel;
	}
	this->pFlightlevel = pFlightlevel;
}
std::list<CRouteWeatherData*>* CLeg::pGetWeatherData() {
	return &(this->lWeatherData);
}
CLegRestriction* CLeg::pGetLegRestriction(){
	return this->pRestrictions;
}
void CLeg::setLegRestriction(CLegRestriction* pLegRestrictions) {
	if (this->pRestrictions != pRestrictions) {
		delete this->pRestrictions;
	}
	this->pRestrictions = pLegRestrictions;
}
CPerformanceData* CLeg::pGetPerformanceData() {
	return this->pLegPerformance;
}
void CLeg::setPerformanceData(CPerformanceData* pPerformanceData) {
	if (this->pLegPerformance != pLegPerformance) {
		delete this->pLegPerformance;
	}
	this->pLegPerformance = pPerformanceData;
}



CRoute::CRoute() {
	pDepartureAirport = NULL;
	pDestinationAirport = NULL;
	pAircraftData = NULL;

}
CRoute::CRoute(CAirport* pDepartureAirport, CAirport* pDestinationAirport, CAircraftData* pAircraftData) {
	this->setDeparture(pDepartureAirport);
	this->setDestination(pDestinationAirport);
	this->setAircraftData(pAircraftData);
}
CRoute::~CRoute() {

}
CAirport* CRoute::pGetDeparture() {
	return this->pDepartureAirport;
}
void CRoute::setDeparture(CAirport* pDepartureAirport) {
	if (this->pDepartureAirport != pDepartureAirport) {
		delete this->pDepartureAirport;
	}
	this->pDepartureAirport = pDepartureAirport;
}
CAirport* CRoute::pGetDestination() {
	return this->pDepartureAirport;
}
void CRoute::setDestination(CAirport* pDestinationAirport) {
	if (this->pDestinationAirport != pDestinationAirport) {
		delete this->pDestinationAirport;
	}
	this->pDestinationAirport = pDestinationAirport;
}
CAircraftData* CRoute::pGetAircraftData() {
	return this->pAircraftData;
}
void CRoute::setAircraftData(CAircraftData* pAircraftData) {
	if (this->pAircraftData != pAircraftData) {
		delete this->pAircraftData;
	}
	this->pAircraftData = pAircraftData;
}




