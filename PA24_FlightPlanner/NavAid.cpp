#include "NavAid.h"

CWaypoint::CWaypoint() {
	this->uiAltitude = 0;
	this->dLatitude = 0;
	this->dLongitude = 0;
	this->strId = "";
}

CWaypoint::CWaypoint(unsigned int uiAltitude, double dLongitude, double dLatitude, std::string strId) {
	this->setAltitude(uiAltitude);
	this->setLatitude(dLatitude);
	this->setLongitude(dLongitude);
	this->setId(strId);
}

CWaypoint::~CWaypoint() {


}

unsigned int CWaypoint::uiGetAltitude() {
	return uiAltitude;
}
void CWaypoint::setAltitude(unsigned int uiAltitude) {
	this->uiAltitude = uiAltitude;
}
double CWaypoint::dGetLatitude() {
	return dLatitude;
}
void CWaypoint::setLatitude(double dLatitude) {
	this->dLatitude = dLatitude;
}
double CWaypoint::dGetLongitude() {
	return dLongitude;
}
void CWaypoint::setLongitude(double dLongitude) {
	this->dLongitude = dLongitude;
}
std::string CWaypoint::strGetId() {
	return strId;
}
void CWaypoint::setId(std::string strId) {
	this->strId = strId;
}


CRadioStation::CRadioStation() : CWaypoint() {
	this->fFrequency = 0;
	this->usiType = 0;
	this->strName = "";
	this->usiRange = 0;
}
CRadioStation::CRadioStation(unsigned int uiAltitude, double dLongitude, double dLatitude, std::string strId,
	float fFrequency, unsigned short usiType, std::string strName, unsigned short usiRange)
: CWaypoint(uiAltitude, dLongitude, dLatitude, strId){
	this->setFrequency(fFrequency);
	this->setType(usiType);
	this->setName(strName);
	this->setRange(usiRange);
}
CRadioStation::~CRadioStation() {
	// base destructor is called automatically
}

float CRadioStation::fGetFrequency() {
	return this->fFrequency;
}
void CRadioStation::setFrequency(float fFrequency) {
	this->fFrequency = fFrequency;
}
unsigned short CRadioStation::usiGetType() {
	return this->usiType;
}
void CRadioStation::setType(unsigned short usiType) {
	//check combination of types (effort?)// throw exception if appropiate
	this->usiType = usiType;
}
std::string CRadioStation::strGetName() {
	return strName;
}
void CRadioStation::setName(std::string strName) {
	this->strName = strName;
}
unsigned short CRadioStation::usiGetRange() {
	return usiRange;
}
void CRadioStation::setRange(unsigned short usiRange) {
	this->usiRange = usiRange;
}

CAirport::CAirport():CWaypoint() {
	this->strName = "";
	this->strMetar = "";
	this->strTaf = "";
}
CAirport::CAirport(unsigned int uiAltitude, double dLongitude, double dLatitude, std::string strId, 
	std::string strName):CWaypoint(uiAltitude, dLongitude, dLatitude, strId) {
	this->setName(strName);
}
CAirport::~CAirport() {

}

std::string CAirport::strGetName() {
	return this->strName;
}
void CAirport::setName(std::string strName) {
	this->strName = strName;
}
std::string CAirport::strGetMetar() {
	return this->strName;
}
void CAirport::setMetar(std::string strMetar) {
	this->strMetar = strMetar;
}
std::string CAirport::strGetTaf() {
	return this->strTaf;
}
void CAirport::setTaf(std::string strTaf) {
	this->strTaf = strTaf;
}
std::list<CRunway*>* CAirport::pGetRunwayList() {
	return &(this->lRunways);
}


CRunway::CRunway() {
	this->uiLength = 0;
	this->uiWidth = 0;
	this->uiMaxWeight = 0;
	this->fHeading = 0;
	this->fMaxTailwind = 0;
	this->usiSurfaceType = 0;
}
CRunway::CRunway(unsigned int uiLength, unsigned int uiWidth, unsigned int uiMaxWeight, float fHeading, float fMaxTailwind, unsigned short usiSurfaceType) {
	this->setLength(uiLength);
	this->setWidth(uiWidth);
	this->setMaxWeight(uiMaxWeight);
	this->setHeading(fHeading);
	this->setMaxTailwind(fMaxTailwind);
	this->setSurfaceType(usiSurfaceType);
}
CRunway::~CRunway() {

}

unsigned int CRunway::uiGetLength() {
	return this->uiLength;
}
void CRunway::setLength(unsigned int uiLength) {
	this->uiLength = uiLength;
}
unsigned int CRunway::uiGetWidth() {
	return this->uiWidth;
}
void CRunway::setWidth(unsigned int uiWidth) {
	this->uiWidth = uiWidth;
}
unsigned int CRunway::uiGetMaxWeight() {
	return this->uiMaxWeight;
}
void CRunway::setMaxWeight(unsigned int uiMaxWeight) {
	this->uiMaxWeight = uiMaxWeight;
}
float CRunway::fGetHeading() {
	return this->fHeading;
}
void CRunway::setHeading(float fHeading) {
	this->fHeading = fHeading;
}
float CRunway::fGetMaxTailwind() {
	return this->fMaxTailwind;
}
void CRunway::setMaxTailwind(float fMaxTailwind) {
	this->fMaxTailwind = fMaxTailwind;
}
unsigned short CRunway::usiGetSurfaceType() {
	return this->usiSurfaceType;
}
void CRunway::setSurfaceType(unsigned short usiSurfaceType) {
	this->usiSurfaceType = usiSurfaceType;
}
