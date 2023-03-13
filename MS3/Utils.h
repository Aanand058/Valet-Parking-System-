/* Citation and Sources...
Final Project Milestone ms3
Module: ms3
Filename: Utils.h
Version 1.0
Author	John Doe
Revision History

-----------------------------------------------------------
The Utils is copied from the previous workshops provided by the professor.
-----------------------------------------------------------
Name: Aanand Aman			Student Id: 166125211              Date: 2022/11/18
Email: aaman8@myseneca.ca
-----------------------------------------------------------*/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds
{
	int strlen(const char* str);
	// copies up to len chars from src to des
	// if len is negative, it will copy up to null char
	// resulting a cstring in des in any case
	void strcpy(char* des, const char* src, int len = -1);
	int strcmp(const char* s1, const char* s2);

	const char* toUpperCase(char* string); 


}
#endif // !
