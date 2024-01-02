#include "PassengerDatabase.h"
#include "Passenger.h"
#include "CSVFile.h"
#include <iostream>

PassengerDatabase::PassengerDatabase() { //isLoaded should default to false
    isLoaded = false;
}

PassengerDatabase::~PassengerDatabase() { //just calls the clearAllPassengers() function
    clearAllPassengers();
}

int PassengerDatabase::load(std::string filePath) { 
    cs32::CSVFile file(this); //This inherits from DataCollectorCallback so you can use it as such
    int recordCount = file.readFile(filePath);
    if (recordCount > 0) {
        isLoaded = true; //If there is at least 1 file that means something loaded
    }
    return recordCount;
}

void PassengerDatabase::clearAllPassengers() {
    for (std::vector< Passenger* >::iterator itr = passengers.begin(); itr != passengers.end(); itr++) {
        delete *itr; //iterates through the vector and individually deletes every pointer
    }
    passengers.clear();
}

bool PassengerDatabase::loaded() {
    return isLoaded;
}

// These functions all essentially work the same
// Loop through the passengers vector, and validate using if-statement, if found then push_back into vector/return

Passenger* PassengerDatabase::getPassenger_byName(std::string name) {
    for (int i = 0; i < passengers.size(); i++) {
        if (passengers.at(i)->getName() == name) {
            return passengers.at(i);
        }
    }
    return nullptr;
}

std::vector< Passenger* > PassengerDatabase::getPassengers() {
    return passengers;
}

std::vector< Passenger* > PassengerDatabase::getPassengers_byClass(Class paidClass, bool survived, double minimumFare) {
    std::vector< Passenger* > output;
    for (int i = 0; i < passengers.size(); i++) {
        if (passengers.at(i)->getClass() == paidClass && passengers.at(i)->getSurvived() == survived && passengers.at(i)->getFare() > minimumFare) {
            output.push_back(passengers.at(i));
        }
    }
    return output;

}

std::vector< Passenger* > PassengerDatabase::getPassengers_byEmbarcation(Embarcation embarked, bool survived, double minimumFare) {
    std::vector< Passenger* > output;
    for (int i = 0; i < passengers.size(); i++) {
        if (passengers.at(i)->getEmbarcation() == embarked && passengers.at(i)->getSurvived() == survived && passengers.at(i)->getFare() > minimumFare) {
            output.push_back(passengers.at(i));
        }
    }
    return output;
}

// This is called for every CSV Row
void PassengerDatabase::csvData(std::map< std::string, std::string > row) {
    using namespace std;
    Passenger* passenger = new Passenger();
    // This essentially converts the map into a passenger object using if statements
    for (std::map< std::string, std::string >::iterator itr = row.begin(); itr != row.end(); itr++) {
        if (itr->second == "") {
            //This checks if data is "dirty", and ignores it
        }
        else if (itr->first == "name") {
            passenger->setName(itr->second);
        }
        else if (itr->first == "survived") {
            passenger->setSurvived(itr->second);
        }
        else if (itr->first == "fare") {
            passenger->setFare(itr->second);
        }
        else if (itr->first == "embarked") {
            passenger->setEmbarcation(itr->second);
        }
        else if (itr->first == "pclass") {
            passenger->setClass(itr->second);
        }
    }
    passengers.push_back(passenger);

}