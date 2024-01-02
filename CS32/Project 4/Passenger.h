#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include "Enums.h"

class Passenger
{
public:
	Passenger();
	void setName(std::string name);
	std::string getName();
	
	void setEmbarcation(std::string embarked);
	void setFare(std::string fare);
	void setSurvived(std::string survived);
	void setClass(std::string classOfFare);

	Embarcation getEmbarcation();
	double getFare();
	bool getSurvived();
	Class getClass();
private:
	Class mClass;
	std::string mName;
	Embarcation mEmbarcked;
	bool mSurvived;
	double mFare;
};

#endif

