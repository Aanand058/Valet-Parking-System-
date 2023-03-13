/* Citation and Sources...
Final Project Milestone ms1
Module: ms1
Filename: Menu.cpp
Version 1.0
Author	John Doe
Revision History

-----------------------------------------------------------
During this project, I was facing problem in the indendation part, so i took help from one of my friend
who is not a student of Seneca college. He helped me to implement the indentation output correctly in the display function to
make it work properly. The name of my friend is Ashutosh Jha, email: jhaashutosh.aj@gmail.com
-----------------------------------------------------------
Name: Aanand Aman			Student Id: 166125211              Date: 2022/11/8
Email: aaman8@myseneca.ca
-------------- ---------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds
{


	//*********************** MENUITEM ***********************
	MenuItem::MenuItem()
	{
		this->m_item[0] = '\0';

	}

	MenuItem::~MenuItem()
	{
		this->m_item[0] = '\0';


	}

	MenuItem::MenuItem(const char* itemname)
	{
		if (itemname != nullptr)
		{
			strcpy(this->m_item, itemname, 50);
		}
		else
		{
			this->m_item[0] = '\0';
		}

	}

	std::ostream& MenuItem::display(std::ostream& ostr) const
	{
		if (this->m_item != NULL)
		{
			ostr << this->m_item << endl;
		}

		return ostr;
	}



	//***************** MENU ********************
	Menu::Menu()
	{
		this->n_title[0] = '\0';

		for (int i = 0; i < this->n_noOfItem; i++)
		{
			this->n_MenuItems[i].m_item[0] = '\0';
		}

		this->n_indentation = 0;
		this->n_noOfItem = 0;
	}

	Menu::Menu(const char* titleSrc)
	{
		if (titleSrc != nullptr)
		{
			strcpy(this->n_title, titleSrc, 50);
			this->n_noOfItem = 0;
			this->n_indentation = 0;

		}
		else
		{
			clear();
		}


	}



	Menu::Menu(const char* titleSrc, int indent)
	{
		if (titleSrc != nullptr)
		{
			strcpy(this->n_title, titleSrc, 50);
			this->n_indentation = indent;
			this->n_noOfItem = 0;

		}
		else
		{
			clear();
		}

	}

	void Menu::clear()  //Setting everything to empty state 
	{

		this->n_title[0] = '\0';

		for (int i = 0; i < this->n_noOfItem; i++)
		{
			this->n_MenuItems[i].m_item[0] = '\0';
		}

		this->n_noOfItem = 0;
		this->n_indentation = 0;
	}

	Menu::~Menu()
	{
		this->n_title[0] = '\0';

		for (int i = 0; i < MAX_NO_OF_ITEMS; i++)
		{
			this->n_MenuItems[i].m_item[0] = '\0';
		}

		this->n_indentation = 0;
		this->n_noOfItem = 0;


	}


	void Menu::indentOutput() const
	{
		for (int i = 0; i < this->n_indentation; i++)
		{
			cout << "    ";
		}

	}

	Menu::operator bool() const
	{
		return !isEmpty();
	}

	bool Menu::isEmpty() const
	{
		if (this->n_title[0] == '\0' && this->n_noOfItem <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	std::ostream& Menu::display(std::ostream& ostr) const
	{
		if (isEmpty())
		{
			ostr << "Invalid Menu!" << endl;
		}
		else
		{
			indentOutput();
			
			if (this->n_noOfItem == 0)
			{
				ostr << this->n_title << endl;
				ostr << "No Items to display!" << endl;
			}
			else
			{
				ostr << this->n_title << endl;
				int options = 1, i;
				for (i = 0; i < this->n_noOfItem; i++)
				{
					indentOutput();
					ostr << options << "- ";
					ostr << this->n_MenuItems[i].m_item << endl;
					options++;
				}
				indentOutput();
				ostr << "> ";
			}
		}
		return ostr;
	}

	Menu& Menu::operator=(const char* toCopyFrom)
	{

		if (toCopyFrom != nullptr)
		{
			strcpy(this->n_title, toCopyFrom, 50);
		}
		else
		{
			clear();
		}

		return *this;
	}

	void Menu::add(const char* items)
	{
		if (items == nullptr)
		{
			clear();
		}

		if (!isEmpty() && this->n_noOfItem <= MAX_NO_OF_ITEMS)
		{
			strcpy(this->n_MenuItems[this->n_noOfItem].m_item, items, 50);
			//this->n_indentation = 1; 
			this->n_noOfItem++;
		}


	}

	Menu& Menu::operator<<(const char* menuitmes)
	{
		add(menuitmes);
		return *this;

	}

	int Menu::run() const
	{
		int input = 0; //Taking user input 
		int flag = 0;  //Flag variable for breaking the loop 

		if (this->n_noOfItem > 0)
		{
			display();

			for (int i = 0; flag == 0; i++)
			{

				cin >> input;

				if (cin.fail())
				{
					cout << "Invalid Integer, try again: ";
					cin.clear();
				}
				else
				{
					if (input > 0 && input <= this->n_noOfItem)
					{
						flag = 1;
						cin.clear();
					}
					else
					{
						cout << "Invalid selection, try again: ";
						cin.clear();
					}
				}
				cin.ignore(1000, '\n');
			}
			return input;
		}
		else
		{
			display();
			return 0;
		}
	}

	Menu::operator int() const
	{
		return run();
	}



}