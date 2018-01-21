#pragma once

/****
Units:

SI units first, then derived / imperial units

  1xx: length
  2xx: mass
  3xx: volume
  4xx: velocity
  5xx: volume flow rate
  6xx: mass flow rate
  7xx: temperature
  8xx: angle

xxx00: SI / base unit (the unit in which value is saved) 
xxxyy: other units


ToDo:
derived units (e.g. volume flow rate): use volume unit and time unit => many flow rate units can be realised without much effort

**/

class CVolume {
	/*
	ToDo:
		-
	*/
public:
	CVolume(double dValue, unsigned short usiUnit);
	~CVolume();

	double dGetCubicMeters();
	double dGetUsLiqGallons();
	double dGetLiters();
	double dGetUsLiqQuarts();

#define Unit_Volume_CubicMeter 300
#define Unit_Volume_UsLiqGallon 301
#define Unit_Volume_Liter 302
#define Unit_Volume_UsLiqQuart 303
private:
	double dValue;
};

class CMass {
	/*
	ToDo:
		-
	*/
public:
	CMass(double dValue, unsigned short usiUnit);
	~CMass();

	double dGetKilograms();
	double dGetPounds();

#define Unit_Mass_Kilogram 200
#define Unit_Mass_Pound 201
private:
	double dValue;
};

class CVelocity {
	/*
	ToDo:
		-
	*/
public:
	CVelocity(double dValue, unsigned short usiUnit);
	~CVelocity();

	double dGetMetersPerSecond();
	double dGetMilesPerHour();
	double dGetKnots();
	double dGetKilometersPerHour();
#define Unit_Velocity_MetersPerSecond 400
#define Unit_Velocity_MilesPerHour 401
#define Unit_Velocity_Knots 402
#define Unit_Velocity_KilometersPerHour 403
private:
	double dValue;
};

class CLength {
	/*
	ToDo:
		-
	*/
public:
	CLength(double dValue, unsigned short usiUnit);
	~CLength();

	double dGetMeters();
	double dGetFeet();
	double dGetKilometers();
	double dGetInch();
	double dGetCentimeters();
	double dGetFlightlevels();
#define Unit_Length_Meters 100
#define Unit_Length_Feet 101
#define Unit_Length_Kilometers 102
#define Unit_Length_Inch 103
#define Unit_Length_Centimeters 104
#define Unit_Length_Flightlevel 105
private:
	double dValue;
};

class CVolumeFlowRate {
	/*
	ToDo:
		-
	*/
public:
	CVolumeFlowRate(double dValue, unsigned short usiUnit);
	~CVolumeFlowRate();

	double dGetCubicmetersPerSecond();
	double dGetLitersPerHour();
	double dGetUsLiqGallonsPerHour();

#define Unit_VolumeFlowRate_CubicmetersPerSecond 500
#define Unit_VolumeFlowRate_LitersPerHour 501
#define Unit_VolumeFlowRate_UsLiqGallonsPerHour 502
private:
	double dValue;
};

class CMassFlowRate {
	/*
	ToDo:
		-
	*/
public:
	CMassFlowRate(double dValue, unsigned short usiUnit);
	~CMassFlowRate();

	double dGetKilogramsPerSecond();
	double dGetKilogramsPerHour();
	double dGetPoundsPerHour();

#define Unit_MassFlowRate_KilogramsPerSecond 600
#define Unit_MassFlowRate_KilogramsPerHour 601
#define Unit_MassFlowRate_PoundsPerHour 602

private:
	double dValue;

};

class CTemperature {
	/*
	ToDo:
		-
	*/
public:
	CTemperature(double dValue, unsigned short usiUnit);
	~CTemperature();

	double dGetKelvin();
	double dGetDegreeCelsius();
	double dGetDegreeFahrenheit();

#define Unit_Temperature_Kelvin 700
#define Unit_Temperature_DegreeCelsius 701
#define Unit_Temperature_DegreeFahrenheit 702


private:
	double dValue;
};

class CAngle {
	/*
	ToDo:
		-
	*/
public:
	CAngle(double dValue, unsigned short usiUnit);
	~CAngle();

	double dGetRadiants();
	double dGetDegrees();

#define Unit_Angle_Radiant 800
#define Unit_Angle_Degree 801
private:
	double dValue;
};