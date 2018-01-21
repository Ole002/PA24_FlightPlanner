#include "AircraftData.h"

CWeight::CWeight() {
	this->setMaxWeight(new CMass(0,Unit_Mass_Kilogram));
	this->setLocation(new CLength(0, Unit_Length_Meters));
}
CWeight::CWeight(CLength* pLocation, CMass* pMaxWeight) {
	this->setMaxWeight(pMaxWeight);
	this->setLocation(pLocation);
}
CWeight::~CWeight() {
	delete this->pMaxWeight;
	delete this->pWeight;
	delete this->pLocation;
}
CMass* CWeight::pGetMaxWeight() {
	return this->pMaxWeight;
}
void CWeight::setMaxWeight(CMass* pMaxWeight){
	if (this->pMaxWeight != pMaxWeight) {
		delete this->pMaxWeight;
	}
	this->pMaxWeight = pMaxWeight;
}
CMass* CWeight::pGetWeight() {
	return this->pWeight;
}
void CWeight::setWeight(CMass* pWeight) {
	if (this->pWeight != pWeight) {
		delete this->pWeight;
	}
	this->pWeight = pWeight;
}
CLength* CWeight::pGetLocation() {
	return this->pLocation;
}
void CWeight::setLocation(CLength* pLocation) {
	if (this->pLocation != pLocation) {
		delete this->pLocation;
	}
	this->pLocation = pLocation;
}
unsigned short CWeight::usiGetType() {
	return this->usiType;
}
void CWeight::setType(unsigned short usiType) {
	this->usiType = usiType;
}
std::string CWeight::strGetName() {
	return this->strName;
}
void CWeight::setName(std::string strName) {
	this->strName = strName;
}

double CPerformanceData::dGetTimeStamp() {
	return this->dTimeStamp;
}
void CPerformanceData::setTimeStamp(double dTimeStamp) {
	if (dTimeStamp > 0) {
		this->dTimeStamp = dTimeStamp;
	}
}
CPerformanceData::CPerformanceData() {
	this->setIas(new CVelocity(0, Unit_Velocity_MetersPerSecond));
	this->setFuelFlow(new CVolumeFlowRate(0, Unit_VolumeFlowRate_CubicmetersPerSecond));
}
CPerformanceData::CPerformanceData(CVelocity* pIas, CVolumeFlowRate* pFuelflow) {
	this->setIas(pIas);
	this->setFuelFlow(pFuelFlow);
}
CPerformanceData::~CPerformanceData() {
	delete this->pIas;
	delete this->pFuelFlow;
}
CVelocity* CPerformanceData::pGetIas() {
	return this->pIas;
}
void CPerformanceData::setIas(CVelocity* pIas) {
	if (this->pIas != pIas) {
		delete this->pIas;
	}
	this->pIas = pIas;
}
CVolumeFlowRate* CPerformanceData::pGetFuelFlow() {
	return this->pFuelFlow;
}
void CPerformanceData::setFuelFlow(CVolumeFlowRate* pFuelFlow) {
	if (this->pFuelFlow != pFuelFlow) {
		delete this->pFuelFlow;
	}
	this->pFuelFlow = pFuelFlow;	
}
CLength* CPerformanceData::pGetAltitude() {
	return this->pAltitude;
}
void CPerformanceData::setAltitude(CLength* pAltitude) {
	if (this->pAltitude != pAltitude) {
		delete this->pAltitude;
	}
	this->pAltitude = pAltitude;
}

CAltChangePerfData::CAltChangePerfData() :CPerformanceData() {
	this->setAltBegin(new CLength(0, Unit_Length_Meters));
	this->setAltEnd(new CLength(0, Unit_Length_Meters));
}
CAltChangePerfData::CAltChangePerfData(CVelocity* fIas, CVolumeFlowRate* fFuelFlow, CLength* uiAltBegin, CLength* uiAltEnd)
	: CPerformanceData(pIas, pFuelFlow) {
	this->setAltBegin(pAltBegin);
	this->setAltEnd(pAltEnd);
}
CAltChangePerfData::~CAltChangePerfData() {
	delete this->pAltBegin;
	delete this->pAltEnd;
}
CLength* CAltChangePerfData::pGetAltBegin() {
	return this->pAltBegin;
}
void CAltChangePerfData::setAltBegin(CLength* pAltBegin) {
	if (this->pAltBegin != pAltBegin) {
		delete this->pAltBegin;
	}
	this->pAltBegin = pAltBegin;
}
CLength* CAltChangePerfData::pGetAltEnd() {
	return this->pAltEnd;
}
void CAltChangePerfData::setAltEnd(CLength* pAltEnd) {
	if (this->pAltEnd != pAltEnd) {
		delete this->pAltEnd;
	}
	this->pAltEnd = pAltEnd;
}

CAircraftData::CAircraftData() {
	this->setDryEmptyWeight(new CMass(0, Unit_Mass_Kilogram));
	this->setOilWeight(new CMass(0, Unit_Mass_Kilogram));
	this->setMaxCrosswind(new CVelocity(0, Unit_Velocity_MetersPerSecond));
	this->strRegistration = "";
}
CAircraftData::CAircraftData(CMass* pDryEmptyWeight, CMass* pOilWeight, CVelocity* pMaxCrosswind, std::string strRegistration) {
	this->setDryEmptyWeight(pDryEmptyWeight);
	this->setOilWeight(pOilWeight);
	this->setMaxCrosswind(pMaxCrosswind);
	this->setRegistration(strRegistration);

}
CAircraftData::~CAircraftData() {
	delete this->pDryEmptyWeight;
	delete this->pOilWeight;

	//delete all weights
	for (
		std::list<CWeight*>::iterator lWeightIter = lWeights.begin();
		lWeightIter != lWeights.end();
		lWeightIter++)
	{
		delete (*lWeightIter);
	}

	delete this->pMaxCrosswind;

}
CMass* CAircraftData::pGetDryEmptyWeight(){
	return this->pDryEmptyWeight;
}
void CAircraftData::setDryEmptyWeight(CMass* pDryEmptyWeight) {
	if (this->pDryEmptyWeight != pDryEmptyWeight) {
		delete this->pDryEmptyWeight;
	}
	this->pDryEmptyWeight = pDryEmptyWeight;
}
CMass* CAircraftData::pGetOilWeight() {
	return this->pOilWeight;
}
void CAircraftData::setOilWeight(CMass* pOilyWeight) {
	if (this->pOilWeight != pOilWeight) {
		delete this->pOilWeight;
	}
	this->pOilWeight = pOilWeight;
}
CVelocity* CAircraftData::pGetMaxCrosswind() {
	return this->pMaxCrosswind;
}
void CAircraftData::setMaxCrosswind(CVelocity* pMaxCrosswind) {
	if (this->pMaxCrosswind != pMaxCrosswind) {
		delete this->pMaxCrosswind;
	}
	this->pMaxCrosswind = pMaxCrosswind;
}
std::string CAircraftData::strGetRegistration() {
	return this->strRegistration;
}
void CAircraftData::setRegistration(std::string strRegistration) {
	this->strRegistration = strRegistration;
}



CVolume* CAircraftData::pGetFuelCapacity() {
	// iterate through tank list 
	double dFuelCap = 0;
	for (
		std::list<CWeight*>::iterator lWeightIter = lWeights.begin();
		lWeightIter != lWeights.end();
		lWeightIter++)
	{
		if ((*lWeightIter)->usiGetType() == WeightType_Fuel) {
			dFuelCap += (*lWeightIter)->pGetMaxWeight()->dGetPounds();
		}
	}
	// do some unit calculations
	// for now: return fuel as us-gallons
	return new CVolume(dFuelCap/6.25, Unit_Volume_UsLiqGallon); // based on 0.75kg/l at 15 °C
}

CFlightStatus::CFlightStatus() {
	lPerformanceData = new std::list<CPerformanceData*>;
}
CFlightStatus::CFlightStatus(std::list<CPerformanceData*>* plPerformanceData) {

}
CFlightStatus::~CFlightStatus() {

}
void CFlightStatus::addCPerformanceDataObject(CPerformanceData* pPerformanceDataObject) {

}
CPerformanceData* CFlightStatus::getPerformanceData(double dTimeStamp) { return NULL; }

CFlightStatus* CFlightStatus::getFlightStatus(double dTimeStamp) {
	return NULL;
}
