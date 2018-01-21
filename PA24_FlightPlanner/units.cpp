#include "units.h"

CVolume::CVolume(double dValue, unsigned short usiUnit) {
	// convert dValue to SI-Unit if appropriate
	switch (usiUnit) {
	case Unit_Volume_CubicMeter:
		this->dValue = dValue;
		break;
	case Unit_Volume_UsLiqGallon:
		this->dValue = dValue / 264.1720524; // redo: use length conversion?! -> https://de.wikipedia.org/wiki/Gallone
		break;
	case Unit_Volume_Liter:
		this->dValue = dValue / 1000.0;
		break;
	case Unit_Volume_UsLiqQuart:
		this->dValue = dValue / 1056.688209; // redo: use length conversion?!
		break;
	default:
		this->dValue = 0;
	}
}
CVolume::~CVolume() {

}
double CVolume::dGetCubicMeters() {
	return this->dValue;
}
double CVolume::dGetUsLiqGallons() {
	return (this->dValue * 264.1720524);
}
double CVolume::dGetLiters() {
	return (this->dValue / 1000.0);
}
double CVolume::dGetUsLiqQuarts() {
	return (this->dValue / 1056.688209);
}

CMass::CMass(double dValue, unsigned short usiUnit) {
	switch (usiUnit) {
	case Unit_Mass_Kilogram:
		this->dValue = dValue;
		break;
	case Unit_Mass_Pound:
		this->dValue = dValue * 0.45359237;
		break;
	default:
		this->dValue = 0;
	}
}
CMass::~CMass() {

}
double CMass::dGetKilograms() {
	return this->dValue;
}
double CMass::dGetPounds() {
	return (this->dValue * 2.2046226218487758072297380134503);
}

CVelocity::CVelocity(double dValue, unsigned short usiUnit) {
	switch (usiUnit) {
	case Unit_Velocity_MetersPerSecond:
		this->dValue = dValue;
		break;
	case Unit_Velocity_MilesPerHour:
		this->dValue = dValue / 0.44704;
		break;
	case Unit_Velocity_Knots:
		this->dValue = dValue / (1852 / 3600.0);
		break;
	case Unit_Velocity_KilometersPerHour:
		this->dValue = dValue / 3.6;
		break;
	default:
		this->dValue = 0;
	}
}
CVelocity::~CVelocity() {

}
double CVelocity::dGetMetersPerSecond() {
	return this->dValue;
}
double CVelocity::dGetMilesPerHour() {
	return (this->dValue*0.44704);
}
double CVelocity::dGetKnots() {
	return (this->dValue * (1852 / 3600.0));
}
double CVelocity::dGetKilometersPerHour() {
	return (this->dValue *3.6);
}

CLength::CLength(double dValue, unsigned short usiUnit) {
	switch (usiUnit) {
	case Unit_Length_Meters:
		this->dValue = dValue;
		break;
	case Unit_Length_Feet:
		this->dValue = dValue * 0.3048;
		break;
	case Unit_Length_Kilometers:
		this->dValue = dValue * 1000;
		break;
	case Unit_Length_Inch:
		this->dValue = dValue * 0.0254;
		break;
	case Unit_Length_Centimeters:
		this->dValue = dValue * 0.01;
		break;
	case Unit_Length_Flightlevel:
		this->dValue = dValue * 30.48;
	default:
		this->dValue = 0;
	}
}
CLength::~CLength() {

}
double CLength::dGetMeters() {
	return this->dValue;
}
double CLength::dGetFeet() {
	return (this->dValue / 0.3048);
}
double CLength::dGetKilometers() {
	return (this->dValue / 1000.0);
}
double CLength::dGetInch() {
	return (this->dValue / 0.0254);
}
double CLength::dGetCentimeters() {
	return (this->dValue / 0.01);
}
double CLength::dGetFlightlevels() {
	return (this->dValue / 30.48);
}


CVolumeFlowRate::CVolumeFlowRate(double dValue, unsigned short usiUnit) {
	switch (usiUnit) {
	case Unit_VolumeFlowRate_CubicmetersPerSecond:
		this->dValue = dValue;
		break;
	case Unit_VolumeFlowRate_LitersPerHour:
		this->dValue = dValue / 3600000.0;
		break;
	case Unit_VolumeFlowRate_UsLiqGallonsPerHour:
		this->dValue = dValue / 951019.38864;
		break;
	default:
		this->dValue = 0;
	}
}
CVolumeFlowRate::~CVolumeFlowRate() {

}
double CVolumeFlowRate::dGetCubicmetersPerSecond() {
	return this->dValue;
}
double CVolumeFlowRate::dGetLitersPerHour() {
	return (this->dValue * 3600000);
}
double CVolumeFlowRate::dGetUsLiqGallonsPerHour() {
	return (this->dValue * 951019.38864);
}

CMassFlowRate::CMassFlowRate(double dValue, unsigned short usiUnit) {
	switch (usiUnit) {
	case Unit_MassFlowRate_KilogramsPerSecond:
		this->dValue = dValue;
		break;
	case Unit_MassFlowRate_KilogramsPerHour:
		this->dValue = dValue / 3600.0;
		break;
	case Unit_MassFlowRate_PoundsPerHour:
		this->dValue = dValue / 7936.6414387;
		break;
	default:
		this->dValue = 0;
	}
}
CMassFlowRate::~CMassFlowRate() {

}
double CMassFlowRate::dGetKilogramsPerSecond() {
	return this->dValue;
}
double CMassFlowRate::dGetKilogramsPerHour() {
	return this->dValue * 3600;
}
double CMassFlowRate::dGetPoundsPerHour() {
	return this->dValue * 7936.6414387;
}

CTemperature::CTemperature(double dValue, unsigned short usiUnit) {
	switch (usiUnit) {
	case Unit_Temperature_Kelvin:
		this->dValue = dValue;
	case Unit_Temperature_DegreeCelsius:
		this->dValue = dValue + 273.15;
	case Unit_Temperature_DegreeFahrenheit:
		this->dValue = (dValue -32)/1.8+273.15;
	default:
		this->dValue = 0;
	}
}
CTemperature::~CTemperature() {

}
double CTemperature::dGetKelvin() {
	return this->dValue;
}
double CTemperature::dGetDegreeCelsius() {
	return (this->dValue - 273.15);
}
double CTemperature::dGetDegreeFahrenheit() {
	return ((this->dValue - 273.15)*1.8 + 32);
}

CAngle::CAngle(double dValue, unsigned short usiUnit) {
	switch (usiUnit) {
	case Unit_Angle_Radiant:
		this->dValue = dValue;
		break;
	case Unit_Angle_Degree:
		this->dValue = dValue *(360 / 6.28318530718);
		break;
	default:
		this->dValue = 0;
	}
}
CAngle::~CAngle() {

}
double CAngle::dGetRadiants() {
	return this->dValue;
}
double CAngle::dGetDegrees() {
	return (this->dValue / (360 / 6.28318530718));
}


