/*Filename: Parking.cpp
Version 1.0
Author	John Doe
Revision History

---------------------------------------------------------- -
During this milestone I was facing little problem with construtor initialization of Menu as
I was using "(" ")" as bracket in the parking.h file and It was showing error.I used "{" "}" after
searching it in the goolge and found this source:
https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
This helped to me solve the constructor issue.
I also faced error while closing and exiting the parking, to solve that issue I use debugger and different conditional 
methods to get it correct 
---------------------------------------------------------- -
Name : Aanand Aman			Student Id : 166125211              Date : 2022 / 11 / 13
Email : aaman8@myseneca.ca
---------------------------------------------------------- - */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Parking.h"
#include "Utils.h"

using namespace std;

namespace sdds {

    Parking::Parking()
    {
        this->p_filename = nullptr;

    }

    Parking::Parking(const char* filename)
    {
        if (filename != nullptr && filename[0] != '\0') {
            this->p_filename = new char[strlen(filename) + 1];
            strcpy(this->p_filename, filename);

            if (loadDataFile()) {                                         //overloading << to add from the menu.cpp to add in menu 
                this->p_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle" << "Close Parking (End of day)" << "Exit Program";

                this->p_vehicleSelection << "Car" << "Motorcycle" << "Cancel";

            }
            
        }
        else {
            cout << "Error in data file" << endl;
            this->p_filename = nullptr;
        }
    }

    Parking::~Parking()
    {
        savaDataFile();
        delete[] this->p_filename;
        this->p_filename = nullptr;
    }

    bool Parking::isEmpty()const
    {
        if (this->p_filename == nullptr) {
            return true;
        }
        else{
            return false;
        }
    }
        

    void Parking::parkStatus()const
    {
        //cout << endl; 
        cout << "****** Valet Parking ******" << endl;
    }

    void Parking::parkVehicle()const
    {
        switch (this->p_vehicleSelection.run()) {            //calling menu.cpp run method for user input n validation 
        case 1:
            cout << "---------------------------------" << endl;
            cout << "Parking Car" << endl;
            cout << "---------------------------------" << endl;
            cout << endl; 
            break;

        case 2:
            cout << "---------------------------------" << endl;
            cout << "Parking Motorcycle" << endl;
            cout << "---------------------------------" << endl;
              cout << endl; 
            break;

        case 3:
            cout << "---------------------------------" << endl;
            cout << "Cancelled parking" << endl;
            cout << "---------------------------------" << endl;
              cout << endl; 
            break;
        }
    }



     
     void Parking::returnVehicle()const
     {
         cout << "---------------------------------" << endl;
         cout << "Returning Vehicle" << endl;
         cout << "---------------------------------" << endl;
           cout << endl; 

     }
     void Parking::parkListVehicle()const
     {
         cout << "---------------------------------" << endl;
         cout << "Listing Parked Vehicles" << endl;
         cout << "---------------------------------" << endl;
           cout << endl; 
     }
     void Parking::findVehicle()const
     {
         cout << "---------------------------------" << endl;
         cout << "Finding a Vehicle" << endl;
         cout << "---------------------------------" << endl;
           cout << endl; 
     }
     bool Parking::closeParking()const
     {
         cout << "This will close the parking; All the vehicles will be removed!" << endl;
         cout << "Are you sure? (Y)es/(N)o: ";
         char input;
         int flag = 0;
         bool returnValue = false;


         for (int i = 0; flag == 0; i++)
         {
             cin >> input;
             if (input == 'Y' || input == 'y')
             {

                 flag = 1;
                 cin.clear();
                 cin.ignore(1000, '\n');
                 cout << "Ending application!" << endl;
                 returnValue = true;
             }
             else if (input == 'N' || input == 'n') {
                 flag = 1;
                 cin.clear();
                 cin.ignore(1000, '\n');
                 returnValue = false;
             }
             else
             {
                 cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                 cin.clear();
                 cin.ignore(1000, '\n');

             }
         }

       
         return returnValue;
     }

     bool Parking::exitParking()const
     {
         cout << "This will terminate the application and save the data!" << endl;
         cout << "Are you sure? (Y)es/(N)o: ";
         char input;
         int flag = 0;
         bool returnValue = false;

        
         for (int i = 0; flag == 0; i++)
         {
             cin >> input;
             if (input == 'Y' || input == 'y')
             {

                 flag = 1;
                 cin.clear();
                 cin.ignore(1000, '\n');
                 cout << "Exiting application!" << endl;
                 returnValue = true;
             }
             else if (input == 'N' || input == 'n') {
                 flag = 1;
                 cin.clear();
                 cin.ignore(1000, '\n');
                 returnValue = false;
             }
             else
             {
                 cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                 cin.clear();
                 cin.ignore(1000, '\n');

             }
         }

         return returnValue;
     }

    

     bool Parking::loadDataFile()const
     {
         if (!isEmpty()) {
             cout << "---------------------------------" << endl;
             cout << "loading data from " << this->p_filename << endl;
             cout << "---------------------------------" << endl;
             cout << endl;
             return true;
         }
         else
         {
             return false;
         }
     }
     void Parking::savaDataFile()const
     {
         if (!isEmpty()) {
             cout << "---------------------------------" << endl;
             cout << "Saving data into " << this->p_filename << endl;
             cout << "---------------------------------" << endl;
             cout << endl;
            
         }
     }
     int Parking::run()
     {
         int flag = 0;
         bool exit = false; 
         bool close = false; 
         
             if (!isEmpty()) {

                 for (int i = 0; flag == 0; i++) {
                     parkStatus();
                  
                     switch (this->p_parkingMenu.run())
                     {
                     case 1:
                         parkVehicle();
                         break;
                     case 2:
                         returnVehicle();
                         break;
                     case 3:
                         parkListVehicle();
                         break;
                     case 4:
                         findVehicle();
                         break;
                     case 5:
                         close = closeParking();
                         if (close == true) {
                             flag = 1;
                             break;
                         }
                         else
                         {
                             break;
                         }
                     case 6:
                         exit = exitParking();
                         if (exit == true) { flag = 1; break; }
                         else
                         {
                             break; 
                         }
                         
                        
                     }
                 }
             }
         
         return flag;
     }
 }



 