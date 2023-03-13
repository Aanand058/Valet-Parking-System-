/* Citation and Sources...
Final Project Milestone ms4
Module: ms4
Filename: Car.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


#include "Car.h"
#include "Utils.h"

using namespace std;
namespace sdds
{



	Car::Car() :Vehicle()
	{
		this->m_carWashFlag = false;
	}

	Car::Car(const char* plate, const char* makemodel) :Vehicle(plate, makemodel)
	{
		this->m_carWashFlag = false;

	}

	Car::Car(const Car& toCopyFrom) :Vehicle(toCopyFrom)
	{
		*this = toCopyFrom;
	}

	Car& Car::operator=(const Car& toCopyFrom)
	{
		if (this != &toCopyFrom) {
			Vehicle::operator=(toCopyFrom);

			this->m_carWashFlag = toCopyFrom.m_carWashFlag;
		}
		return *this;
	}

	Car::~Car()
	{

	}

	std::ostream& Car::writeType(std::ostream& ostr) const
	{
		if (isCsv()) {
			ostr << "C,";
		}
		else {
			ostr << "Vehicle type: Car" << endl;
		}
		return ostr;
	}

	std::istream& Car::read(std::istream& istr)
	{
		if (isCsv())
		{
			Vehicle::read(istr);
			istr >> m_carWashFlag;
			istr.ignore(1000, '\n');
		}
		else
		{
			cout << endl << "Car information entry" << endl;
			Vehicle::read(istr);
			cout << "Carwash while parked? (Y)es/(N)o: ";
			char input[5];
			do {

				cin >> input;
				if (strlen(input) > 1) {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

				}
				else if (input[0] == 'y') {
					this->m_carWashFlag = true;
					break;

				}
				else if (input[0] == 'n') {
					this->m_carWashFlag = false;
					break;
				}
				else {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				}
			} while (this->m_carWashFlag == false);


		}
		return istr;
	}

	std::ostream& Car::write(std::ostream& ostr) const
	{
		if (isEmpty()) {
			ostr << "Invalid Car Object" << endl;
		}

		else {
			//writeType(ostr);
			Vehicle::write(ostr);
			if (isCsv()) {
				ostr << m_carWashFlag << endl;
			}
			else
			{
				if (this->m_carWashFlag) {
					ostr << "With Carwash" << endl;
				}
				else {
					ostr << "Without Carwash" << endl;
				}


			}

		}
		return ostr;
	}

}