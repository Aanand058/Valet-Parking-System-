/* Citation and Sources...
Final Project Milestone ms4
Module: ms4
Filename: Car.h
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
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle{
		bool m_carWashFlag;

	public:
		//Constructors
		Car();
		Car(const char* plate, const char* makemodel);

		//Rule of three
		Car(const Car& toCopyFrom);
		Car& operator=(const Car& toCopyFrom);
		~Car();

		//writeType
		std::ostream& writeType(std::ostream& ostr) const; 

		//Read
		std::istream& read(std::istream& istr);

		//Write
		std::ostream& write(std::ostream& ostr) const;


	};
	

}
#endif // !
