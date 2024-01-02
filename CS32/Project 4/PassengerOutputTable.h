#ifndef OUTPUT_TABLE_H
#define OUTPUT_TABLE_H

#include <vector>

#include "Passenger.h"
#include "Enums.h"
#include "OutputTableRow.h"

class PassengerOutputTable
{
	public:
		PassengerOutputTable(std::vector< Passenger* > passengers);

		void setOutputField(Field f);
		void setDescription(std::string description);

		Field getOutputField();
		std::string getDescription();

		void display();
		size_t rowCount();
		OutputTableRow getRow(int index);

	private:
		std::vector< Passenger* > mPassengerList;
		std::vector< OutputTableRow > mRows;
		Field mField;
		std::string mDescription;
};

#endif

