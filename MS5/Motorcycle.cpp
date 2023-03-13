/* Citation and Sources...
Final Project Milestone ms4
Module: ms4
Filename: Motorcycle.cpp
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


#include "Motorcycle.h"
#include "Utils.h"

using namespace std;
namespace sdds
{



	Motorcycle::Motorcycle()
	{
		this->m_sideCar = false;
	}

	Motorcycle::Motorcycle(const char* plate, const char* makemodel) :Vehicle(plate, makemodel)
	{
		this->m_sideCar = false;
	}

	Motorcycle::Motorcycle(const Motorcycle& toCopyFrom) :Vehicle(toCopyFrom)
	{
		*this = toCopyFrom;
	}

	Motorcycle& Motorcycle::operator=(const Motorcycle& toCopyrom)
	{
		if (this != &toCopyrom) {
			Vehicle::operator=(toCopyrom);
			this->m_sideCar = toCopyrom.m_sideCar;
		}
		return *this;
	}

	Motorcycle::~Motorcycle()
	{
	}

	std::ostream& Motorcycle::writeType(std::ostream& ostr) const
	{
		if (isCsv()) {
			ostr << "M,";
		}
		else {
			ostr << "Vehicle type: Motorcycle" << endl;
		}
		return ostr;
	}

	std::istream& Motorcycle::read(std::istream& istr)
	{
		if (isCsv()) {
			Vehicle::read(istr);
			istr >> this->m_sideCar;
			istr.ignore(1000, '\n');
		}
		else
		{
			cout << endl << "Motorcycle information entry" << endl;
			Vehicle::read(istr);
			this->m_sideCar = false;
			char input[5];
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";

			do {

				cin >> input;
				if (strlen(input) > 1) {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

				}
				else if (input[0] == 'y') {
					this->m_sideCar = true;
					break;

				}
				else if (input[0] == 'n') {
					this->m_sideCar = false;
					break;
				}
				else {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				}
			} while (this->m_sideCar == false);

		}
		return istr;
	}

	std::ostream& Motorcycle::write(std::ostream& ostr) const
	{
		if (isEmpty()) {
			ostr << "Invalid Motorcycle Object" << endl;
		}
		else {
			Vehicle::write(ostr);
			//	writeType(ostr);
			if (isCsv()) {
				ostr << this->m_sideCar << endl;
			}
			else if (this->m_sideCar)
			{
				ostr << "With Sidecar" << endl;
			}
		}
		return ostr;
	}

}