#include "OutputTableRow.h"
#include <iostream>

OutputTableRow::OutputTableRow() {
	mDescription = "";
	mSurvived = 0;
	mTotal = 0;
}

void OutputTableRow::setDescription(std::string description) {
	mDescription = description;
}
void OutputTableRow::setSurvived(int survived) {
	mSurvived = survived;
}
void OutputTableRow::setTotal(int total) {
	mTotal = total;
}

std::string OutputTableRow::getDescription() {
	return mDescription;
}
int OutputTableRow::getSurvived() {
	return mSurvived;
}
int OutputTableRow::getTotal() {
	return mTotal;
}

// Calculates the percentage, must static cast to double to preserve decimal
double OutputTableRow::getPercentage() {
	if (mTotal == 0) { //Prevents dividing by zero
		return 0.0;
	}
	return static_cast<double>(mSurvived) / static_cast<double>(mTotal);
}
//Displays formatted data
void OutputTableRow::display(){
	std::cout << mDescription << " - \t" << mSurvived << "\t" << mTotal << "\t" << getPercentage()*100.0 << std::endl;
}

// Helper function to pad percentages for prettier styling
std::string OutputTableRow::padToThreeCharacters(int value){
	if (value < 10) {
		return "  " + std::to_string(value);
	}
	else if (value < 100) {
		return " " + std::to_string(value);
	}
	return std::to_string(value);
}