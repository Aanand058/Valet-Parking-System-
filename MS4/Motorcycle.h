/* Citation and Sources...
Final Project Milestone ms4
Module: ms4
Filename: Motorcycle.h
Version 1.0
Author	John Doe
Revision History

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
Name: Aanand Aman			Student Id: 166125211              Date: 2022/11/23
Email: aaman8@myseneca.ca
-----------------------------------------------------------*/
#ifndef SDDS_MOTORCYCLE_H__
#define SDDS_MOTORCYCLE_H__
#include "Vehicle.h"

namespace sdds
{
	class Motorcycle :public Vehicle {
		bool m_sideCar;

	public:
		//Construtor
		Motorcycle();

		Motorcycle(const char* plate, const char* makemodel);


		//Rule of three 
		Motorcycle(const Motorcycle& toCopyFrom);
		Motorcycle& operator=(const Motorcycle& toCopyrom);
		~Motorcycle();


		//writeType
		std::ostream& writeType(std::ostream& ostr) const;


		//read
		std::istream& read(std::istream& istr);

		//write
		std::ostream& write(std::ostream& ostr) const;
	};


}
#endif // !
