#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <map>
#include "Passenger.h"
#include "DataCollectorCallback.h"
#include "Enums.h"

class PassengerDatabase : public cs32::DataCollectorCallback
{
	public:
		PassengerDatabase();
		~PassengerDatabase();

		int load(std::string filePath);
		void clearAllPassengers();
		bool loaded();

		Passenger* getPassenger_byName(std::string name);
		std::vector< Passenger* > getPassengers();
		std::vector< Passenger* > getPassengers_byClass(Class paidClass, bool survived, double minimumFare);
		std::vector< Passenger* > getPassengers_byEmbarcation(Embarcation emarked, bool survived, double minimumFare);

		virtual void csvData(std::map< std::string, std::string > row);

	private:
		std::vector< Passenger* > passengers;
		bool isLoaded;
};

#endif

