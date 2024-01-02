#include "PassengerOutputTable.h"
#include "Enums.h"

#include <map>
#include <string>
#include <iostream>

//Defaults field and description 
PassengerOutputTable::PassengerOutputTable(std::vector< Passenger* > passengers) {
	mPassengerList = passengers;
	mField = Field::NOVALUE;
	mDescription = "";
}

//Setters
void PassengerOutputTable::setOutputField(Field f) {
	mField = f;
}

void PassengerOutputTable::setDescription(std::string description) {
	mDescription = description;
}

//Getters
Field PassengerOutputTable::getOutputField() {
	return mField;
}

std::string PassengerOutputTable::getDescription() {
	return mDescription;
}



void PassengerOutputTable::display() {
	if (mField == Field::NOVALUE) { //Checks if there even is a field to sort by
		return;
	}
	std::map < std::string, std::pair<int, int> > categories;  // Uses a map to hold data, string -> description,  first int -> survived, second int -> total
	for (int i = 0; i < 4; i++) { //All fields have 4 rows, so make them in advance
		OutputTableRow row;
		mRows.push_back(row);
	}
	/* 
	I apologize in advance to any TAs reading this code
	I know this is terrible practice but it was already too late
	*/
	if (mField == Field::BYCLASS) {
		// Initialize the map with information
		// Reason behind the first character behind the actual description is because maps are automatically sorted
		// This means that it would be out of order with NotKnown coming before Second
		categories["aFirst Class"] = { 0,0 };
		categories["bSecond Class"] = { 0,0 };
		categories["cThird Class"] = { 0,0 };
		categories["dNot Known"] = { 0,0 };
		for (Passenger* pass : mPassengerList) {
			if (pass->getClass() == Class::FIRST) {
				if (pass->getSurvived() == true) 
					categories["aFirst Class"].first++; //Increment survived if pass survivedd
				categories["aFirst Class"].second++; // Increment total
			}
			else if (pass->getClass() == Class::SECOND) {
				if (pass->getSurvived() == true)
					categories["bSecond Class"].first++;
				categories["bSecond Class"].second++;
			}
			else if (pass->getClass() == Class::THIRD) {
				if (pass->getSurvived() == true)
					categories["cThird Class"].first++;
				categories["cThird Class"].second++;
			}
			else if (pass->getClass() == Class::NOTKNOWN) {
				if (pass->getSurvived() == true)
					categories["dNot Known"].first++;
				categories["dNot Known"].second++;
			}
		}
	}
	// The following else ifs use the exact same logic as before
	else if (mField == Field::BYEMBARCATION) {
		categories["aCherbourg"] = { 0,0 };
		categories["bQueenstown"] = { 0,0 };
		categories["cSouthhampton"] = { 0,0 };
		categories["dNot Known"] = { 0,0 };
		for (Passenger* pass : mPassengerList) {
			if (pass->getEmbarcation() == Embarcation::CHERBOURG) {
				if (pass->getSurvived() == true)
					categories["aCherbourg"].first++;
				categories["aCherbourg"].second++;
			}
			else if (pass->getEmbarcation() == Embarcation::QUEENSTOWN) {
				if (pass->getSurvived() == true)
					categories["bQueenstown"].first++;
				categories["bQueenstown"].second++;
			}
			else if (pass->getEmbarcation() == Embarcation::SOUTHHAMPTON) {
				if (pass->getSurvived() == true)
					categories["cSouthhampton"].first++;
				categories["cSouthhampton"].second++;
			}
			else if (pass->getEmbarcation() == Embarcation::NOTKNOWN) {
				if (pass->getSurvived() == true)
					categories["dNot Known"].first++;
				categories["dNot Known"].second++;
			}
		}
	}
	else if (mField == Field::BYFARE) {
		categories["a$1-$10"] = { 0,0 };
		categories["b$10-$25"] = { 0,0 };
		categories["c$25-$50"] = { 0,0 };
		categories["d>$50  "] = { 0,0 };
		for (Passenger* pass : mPassengerList) {
			if (pass->getFare() >= 1.0 && pass->getFare() < 10.0) {
				if (pass->getSurvived() == true)
					categories["a$1-$10"].first++;
				categories["a$1-$10"].second++;
			}
			else if (pass->getFare() >= 10.0 && pass->getFare() < 25.0) {
				if (pass->getSurvived() == true)
					categories["b$10-$25"].first++;
				categories["b$10-$25"].second++;
			}
			else if (pass->getFare() >= 25.0 && pass->getFare() < 50) {
				if (pass->getSurvived() == true)
					categories["c$25-$50"].first++;
				categories["c$25-$50"].second++;
			}
			else if (pass->getFare() >= 50) {
				if (pass->getSurvived() == true)
					categories["d>$50  "].first++;
				categories["d>$50  "].second++;
			}
		}

	}
	int counter = 0; // cannot loop through using for int i = 0 so I keep track of index manually
	std::cout << "    " << mDescription << std::endl; //Prints the headers of the table
	std::cout << "                Survived/Total  %" << std::endl;
	// Uses iterators to loop through the maps
	for (std::map < std::string, std::pair<int, int> >::iterator itr = categories.begin(); itr != categories.end(); itr++) {
		std::string description = itr->first;
		description = description.erase(0, 1);
		mRows.at(counter).setDescription(description);
		mRows.at(counter).setSurvived(itr->second.first); //Confusing and gross I know... assigning each row to its respective member variables
		mRows.at(counter).setTotal(itr->second.second);
		mRows.at(counter).display(); //Calls the display for each specific one
		counter++;
	}
}

size_t PassengerOutputTable::rowCount() {
	return mRows.size();
}

OutputTableRow PassengerOutputTable::getRow(int index) {
	return mRows.at(index);
}