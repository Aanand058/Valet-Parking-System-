/* Citation and Sources...
Final Project Milestone ms3
Module: ms3
Filename: ReadWritable.cpp
Version 1.0
Author	John Doe
Revision History

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
Name: Aanand Aman			Student Id: 166125211              Date: 2022/11/018
Email: aaman8@myseneca.ca
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


#include "ReadWritable.h"

using namespace std;
namespace sdds
{


	ReadWritable::ReadWritable()
	{
		this->m_flag = false;
	}

	ReadWritable::~ReadWritable()
	{
	}


	bool ReadWritable::isCsv() const
	{

		return this->m_flag;
	}

	void ReadWritable::setCsv(bool value)
	{
		this->m_flag = value;

	}

	std::ostream& operator<<(std::ostream& ostr, const ReadWritable& r)
	{
		r.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& is, ReadWritable& r)
	{
		r.read(is);
		return is;
	}

}