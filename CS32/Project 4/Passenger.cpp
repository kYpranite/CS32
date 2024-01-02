#include "Passenger.h"

Passenger::Passenger() { //constructor, initializes to default
	mEmbarcked = Embarcation::NOTKNOWN;
	mFare = 0.0;
	mClass = Class::NOTKNOWN;
	mSurvived = false;
	mName = "";
}
//setters use if statements to convert from string
void Passenger::setName(std::string name) { 
	mName = name;
}
std::string Passenger::getName() {
	return mName;
}

void Passenger::setEmbarcation(std::string embarked) {
	if (embarked == "C") {
		mEmbarcked = Embarcation::CHERBOURG;
	}else if (embarked == "Q"){
		mEmbarcked = Embarcation::QUEENSTOWN;
	}
	else if (embarked == "S") {
		mEmbarcked = Embarcation::SOUTHHAMPTON;
	}else{
		mEmbarcked = Embarcation::NOTKNOWN;
	}
}
void Passenger::setFare(std::string fare) {
	mFare = std::stof(fare);
}
void Passenger::setSurvived(std::string survived) {
	if (survived == "0") {
		mSurvived = false;
	}
	else if (survived == "1") {
		mSurvived = true;
	}
	else {
		mSurvived = false;
	}
}
void Passenger::setClass(std::string classOfFare) { 
	if (classOfFare == "1") {
		mClass = Class::FIRST;
	}
	else if (classOfFare == "2") {
		mClass = Class::SECOND;
	}
	else if (classOfFare == "3") {
		mClass = Class::THIRD;
	}
	else {
		mClass = Class::NOTKNOWN;
	}
}

//getters

Embarcation Passenger::getEmbarcation() {
	return mEmbarcked;
}
double Passenger::getFare() {
	return mFare;
}
bool Passenger::getSurvived() {
	return mSurvived;
}
Class Passenger::getClass() {
	return mClass;
}
