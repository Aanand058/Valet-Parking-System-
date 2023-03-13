/* Citation and Sources...
Final Project Milestone ms3
Module: ms3
Filename: Vehicle.cpp
Version 1.0
Author	John Doe
Revision History

-----------------------------------------------------------
In this part I got lots of errors, one was about strcmp, which my professor helped me to fix and
another in the  const char* getLicensePlate() const; where i was not putting const at first 
and it was showing error return value type does not match the function type.
For solving that I tried placing const at front and it worked. 

I was not able to implent the Uppercase of Licence Plate, My friend Ka Ho Chow, email: kchow25@myseneca.ca
helped me and provided the code for uppercase:
I placed this code in the Utils module.
  
  
    const char* toUpperCase(char* string) {
        // ref: https://www.digitalocean.com/community/tutorials/string-uppercase-lowercase-c-plus-plus
        for (int i = 0; i < strlen(string); i++) {
            string[i] = toupper(string[i]);
        }
        return string;
    }


-----------------------------------------------------------
Name: Aanand Aman			Student Id: 166125211              Date: 2022/11/21
Email: aaman8@myseneca.ca
-----------------------------------------------------------*/


#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__

#include <iostream>
#include "ReadWritable.h"


namespace sdds
{
	class Vehicle : public ReadWritable {
		char m_plate[8 + 1];
		char* m_makeModel;
		int m_pSpotNum;


	protected:                                     //learnt from milestone 3 overview video by professor fardard
		void setEmpty();

		bool isEmpty() const;

		

		void setMakeModel(const char* value);

		

		

	public:
		//Constructors
		Vehicle();
		Vehicle(const char* plate, const char* makemodel);

		//Copy constructor and assignment 
		Vehicle(const Vehicle& toCopyFrom);
		Vehicle& operator=(const Vehicle& toCopyFrom);

		//Deconstuctor
		~Vehicle();

	
		const char* getLicensePlate() const;

		char* getMakeModel() const;
		void setParkingSpot(int value);
		int getParkingSpot() const;

		bool operator==(const char* plateValue);

		

		std::istream& read(std::istream& is);


		//writeType (Pure virtual)
		virtual std::ostream& writeType(std::ostream& ostr) const = 0;


		std::ostream& write(std::ostream& ostr) const;


	};
	//Comapring two vehilce license plate 
	bool operator==(const Vehicle& v1,const Vehicle& v2);

	



}
#endif // !
