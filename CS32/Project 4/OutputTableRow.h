#ifndef OUTPUT_TABLE_ROW_H
#define OUTPUT_TABLE_ROW_H

#include <string>

class OutputTableRow
{
	public:
		OutputTableRow();

		void setDescription(std::string description);
		void setSurvived(int survived);
		void setTotal(int total);

		std::string getDescription();
		int getSurvived();
		int getTotal();
		double getPercentage();

		void display();

	private:
		std::string mDescription;
		int mSurvived;
		int mTotal;
		std::string padToThreeCharacters(int value);


};

#endif
