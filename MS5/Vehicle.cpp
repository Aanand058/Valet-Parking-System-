

/* Citation and Sources...
Final Project Milestone ms4
Module: ms4
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

Update on Vehicle.cpp: operator=
1. Added this->setCsv(toCopyFrom.isCsv());

2. I was facing memory leaks problem in the matrix, to solve i took help from my friend Chi Fai Lo, email: clo36@myseneca.ca

In the Vehicle.cpp, he helped to change these implementation in the opeator=
if(!isEmpty())
				delete[] this->m_makeModel;
to check the state of vehicle which solved the problem of leaks.


-----------------------------------------------------------
Name: Aanand Aman			Student Id: 166125211              Date: 2022/11/28
Email: aaman8@myseneca.ca
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Vehicle.h"
#include "Utils.h"

using namespace std;
namespace sdds
{



	Vehicle::Vehicle()
	{
		setEmpty();
	}

	Vehicle::Vehicle(const char* plate, const char* makemodel)
	{
		if (plate != nullptr && makemodel != nullptr && strlen(plate) <= 8 && strlen(makemodel) > 1) {
			strcpy(this->m_plate, plate);
			this->m_makeModel = new char[strlen(makemodel) + 1];
			strcpy(this->m_makeModel, makemodel);

		}
		else
		{
			setEmpty();
		}
	}

	Vehicle::Vehicle(const Vehicle& toCopyFrom)
	{
		*this = toCopyFrom;
	}

	Vehicle& Vehicle::operator=(const Vehicle& toCopyFrom)
	{
		if (this != &toCopyFrom) {

			if (!isEmpty())
				delete[] this->m_makeModel;


			this->setCsv(toCopyFrom.isCsv());

			strcpy(this->m_plate, toCopyFrom.m_plate);
			this->m_pSpotNum = toCopyFrom.m_pSpotNum;

			this->m_makeModel = new char[strlen(toCopyFrom.m_makeModel) + 1];
			strcpy(this->m_makeModel, toCopyFrom.m_makeModel);


		}
		return *this;
	}

	Vehicle::~Vehicle()
	{
		delete[] this->m_makeModel;
		this->m_makeModel = nullptr;
	}

	void Vehicle::setEmpty()
	{

		this->m_plate[0] = '\0';
		this->m_makeModel = nullptr;
		this->m_pSpotNum = 0;
	}

	bool Vehicle::isEmpty() const
	{
		if (this->m_plate[0] == '\0' || this->m_makeModel == nullptr || this->m_pSpotNum < 0) {
			return true;
		}
		else { return false; }

	}

	const char* Vehicle::getLicensePlate() const
	{

		return this->m_plate;
	}

	char* Vehicle::getMakeModel() const
	{
		return this->m_makeModel;
	}

	void Vehicle::setMakeModel(const char* value)
	{
		if (value != nullptr) {
			delete[] this->m_makeModel;
			this->m_makeModel = new char[strlen(value) + 1];
			strcpy(this->m_makeModel, value);


		}
		else {
			this->m_makeModel = nullptr;
		}
	}

	int Vehicle::getParkingSpot() const
	{
		return this->m_pSpotNum;
	}

	void Vehicle::setParkingSpot(int value)
	{

		this->m_pSpotNum = value;

	}

	bool Vehicle::operator==(const char* plateValue)
	{
		char tempPlate[8 + 1];
		strcpy(tempPlate, plateValue);
		toUpperCase(tempPlate);
		if (strcmp(this->m_plate, tempPlate)) {
			return true;
		}
		else { return false; }

	}



	std::istream& Vehicle::read(std::istream& is)
	{
		char tempPlate[8 + 1];
		int tempPspot;
		char tempMmodel[60 + 1];

		if (isCsv()) {
			is >> tempPspot;
			is.ignore();
			is.getline(tempPlate, 8, ',');
			strcpy(this->m_plate, toUpperCase(tempPlate));

			is.getline(tempMmodel, 60, ',');

			setParkingSpot(tempPspot);
			setMakeModel(tempMmodel);

		}
		else {

			cout << "Enter License Plate Number: ";
			is >> tempPlate;
			cin.clear();
			is.ignore(1000, '\n');

			for (int i = 0; strlen(tempPlate) > 8; i++) {
				cout << "Invalid License Plate, try again: ";
				is >> tempPlate;

				is.ignore(1000, '\n');
			}

			strcpy(this->m_plate, toUpperCase(tempPlate));
			cin.clear();
			cout << "Enter Make and Model: ";
			is.getline(tempMmodel, 61, '\n');


			for (int i = 0; strlen(tempMmodel) < 2 || strlen(tempMmodel) > 60; i++) {
				cout << "Invalid Make and model, try again: ";
				is.getline(tempMmodel, 61, '\n');

			}

			if (is.fail()) {
				setEmpty();

			}
			else {
				setMakeModel(tempMmodel);
				setParkingSpot(0);
			}




		}
		return is;
	}

	std::ostream& Vehicle::write(std::ostream& ostr) const
	{
		if (isEmpty()) {
			ostr << "Invalid Vehicle Object" << endl;
		}
		else {
			writeType(ostr);
			if (isCsv()) {
				ostr << getParkingSpot() << "," << getLicensePlate() << "," << getMakeModel() << ",";
			}
			else {
				ostr << "Parking Spot Number: ";
				if (getParkingSpot() == 0) {
					ostr << "N/A" << endl;
				}
				else {
					ostr << getParkingSpot() << endl;
				}
				ostr << "License Plate: " << getLicensePlate() << endl;
				ostr << "Make and Model: " << getMakeModel() << endl;


			}

		}
		return ostr;
	}


	bool operator==(const Vehicle& v1, const Vehicle& v2)
	{

		char tempPlate[8 + 1];
		strcpy(tempPlate, v1.getLicensePlate());
		toUpperCase(tempPlate);

		char tempPlate2[8 + 1];
		strcpy(tempPlate2, v2.getLicensePlate());
		toUpperCase(tempPlate2);

		if (strcmp(tempPlate, tempPlate2) == 0) {
			return true;
		}
		else { return false; }
	}



}