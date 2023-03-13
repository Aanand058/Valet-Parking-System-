/* Citation and Sources...
Final Project Milestone ms2
Module: ms2
Filename: Parking.h
Version 1.0
Author	John Doe
Revision History

-----------------------------------------------------------
During this milestone I was facing little problem with construtor initialization of Menu as
I was using "(" ")" as bracket in the parking.h file and It was showing error. I used "{" "}" after
searching it in the goolge and found this source:
https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
This helped to me solve the constructor issue. 
-----------------------------------------------------------
Name: Aanand Aman			Student Id: 166125211              Date: 2022/11/13
Email: aaman8@myseneca.ca
-----------------------------------------------------------*/

#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__

#include <iostream>
#include "Menu.h"
 


namespace sdds
{
	class Parking {

		char* p_filename;

		Menu p_parkingMenu{"Parking Menu, select an action:", 0};      //initializing the two parameter constructor of Menu

		Menu p_vehicleSelection{"Select type of the vehicle:", 1};


		bool isEmpty() const;

		void parkStatus()const;

		void parkVehicle()const;

		void returnVehicle()const;

		void parkListVehicle()const;

		void findVehicle()const;

		bool closeParking()const;

		bool exitParking()const;

		bool loadDataFile()const;

		void savaDataFile()const;


		//Extre metho created for validation for close and exit parking as both have same implimentation
		bool closeOrExit() const;

	public:
		//Construtors 
		Parking();
		Parking(const char* filename);


		//Deconstrutor 
		~Parking();

		//copy constructor and assignment is denied 
		Parking(const Parking& toCopyFrom) = delete;
		Parking operator=(const Parking& toCopyFrom) = delete;


		int run();


	};
	

	

}
#endif // !
