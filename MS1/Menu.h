/* Citation and Sources...
Final Project Milestone ms1
Module: ms1
Filename: Menu.h
Version 1.0
Author	John Doe
Revision History

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
Name: Aanand Aman			Student Id: 166125211              Date: 2022/11/07
Email: aaman8@myseneca.ca
-----------------------------------------------------------*/

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

#include <iostream>

#define MAX_NO_OF_ITEMS 10 


namespace sdds
{

	// MenuItem class
	class MenuItem
	{
		char m_item[50 + 1];					

		// Constructors
		MenuItem();
		MenuItem(const char* itemname);

		// Deconstructor 
		~MenuItem();

		// Display using ostream 		
		std::ostream& display(std::ostream& ostr = std:: cout) const;

		// Copy Constructor and Assignment Operator (Copy and asssignment is not allowed)
		MenuItem(const MenuItem& toCopyFrom) = delete;
		MenuItem& operator=(const MenuItem& toCopyFrom) = delete;


		// Menu is a friend of MenuItem
		friend class Menu;
	};

	// Menu Class 
	class Menu
	{

		char n_title[50 + 1];
		MenuItem n_MenuItems[MAX_NO_OF_ITEMS];				//Storing the sub-menus title 
		int n_indentation;
		int n_noOfItem;

	public:

		// Construtors
		Menu();
		Menu(const char* titleSrc);
		Menu(const char* titleSrc, int indent);

		// Deconstrutor
		~Menu();

		// Indentation 
		void indentOutput() const;

		// Copy and Assignment (copying and assignment is not allowed)
		Menu(const Menu& toCopyFrom) = delete;
		Menu& operator=(const Menu& toCopyFrom) = delete;

		// bool cast overload
		operator bool() const;

		// isEmpty() function
		bool isEmpty() const;

		// display 
		std::ostream& display(std:: ostream& ostr = std::cout) const;

		// Assignment 
		Menu& operator=(const char* toCopyFrom);

		// add function   (adding sub menus to main menu)
		void add(const char* items);

		// left shift operator overload <<
		Menu& operator<<(const char* menuitmes);

		// Menu class in action (run function) (taking user input here and also validatiing)
		int run() const;

		// Integar cast overload
		operator int() const;

		//Extra method implemented beside from the mandatory instructions
		// Clear to set everything to safe empty state (used in main.cpp)
		void clear();
	};


}
#endif // !
