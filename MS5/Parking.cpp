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

//Rest of the part is mentioned in the reflect.txt
---------------------------------------------------------- -
Name : Aanand Aman			Student Id : 166125211              Date : 2022 / 12 / 08
Email : aaman8@myseneca.ca
---------------------------------------------------------- - */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Parking.h"
#include "Utils.h"
#include "Menu.h"


using namespace std;

namespace sdds {

    Parking::Parking()
    {
        this->p_filename = nullptr;

    }

    Parking::Parking(const char* filename, int noOfSpots)
    {
        if (filename != nullptr && filename[0] != '\0'  && !(noOfSpots < 10 || noOfSpots > MAX_NO_OF_PARKING_SPOTS)) {
            this->p_filename = new char[strlen(filename) + 1];
            strcpy(this->p_filename, filename);
            
            this->p_noOfPSpots = noOfSpots;

            if (loadDataFile()) {                                      
                this->p_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle" << "Close Parking (End of day)" << "Exit Program";

                this->p_vehicleSelection << "Car" << "Motorcycle" << "Cancel";


            }
           

        }
        else {
            cout << "Error in data file" << endl;
            this->p_filename = nullptr;
            this->p_noOfPSpots = 0;
        }
    }

    Parking::~Parking()
    {
        savaDataFile();

        delete[] this->p_filename;
        this->p_filename = nullptr;
        int i;
		for ( i = 0;i < this->p_noOfPSpots;i++)
		  {
			  delete this->p_parkingSpots[i];
			  this->p_parkingSpots[i] = nullptr;
		  }
    }

    bool Parking::isEmpty()const
    {
        if (this->p_filename == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }


    void Parking::parkStatus()const
    {
       
        cout << "****** Valet Parking ******" << endl;
        cout << "*****  Available spots: ";
        cout.width(4);
        cout.setf(ios::left);
        cout << this->p_noOfPSpots - this->p_noOfParkedVehicles;
        cout << " *****" << endl;
    }

    void Parking::parkVehicle()
    {
        if (this->p_noOfPSpots == this->p_noOfParkedVehicles) {
            cout << "Parking is full" << endl;
      }
        else
        {
            switch (this->p_vehicleSelection.run())
            {          
            case 1:
                {

                    Vehicle* newVehilce = new Car;

                    newVehilce->setCsv(false);
                    newVehilce->read(cin);

                    for (int i = 0; i < this->p_noOfPSpots; i++) {
                        if (this->p_parkingSpots[i] == nullptr) {

                            this->p_parkingSpots[i] = newVehilce;
                            this->p_parkingSpots[i]->setParkingSpot(i + 1);

                            cout << endl << "Parking Ticket" << endl;
                            newVehilce->write(cout);

                            this->p_noOfParkedVehicles++;


                        }
                    }

                    
                    cout << endl;
                    cout << "Press <ENTER> to continue...." << endl;
                    break;
                }
                break;

                case 2:
                {


                    Vehicle* newVehilce2 = new Motorcycle;
                    newVehilce2->setCsv(false);
                    newVehilce2->read(cin);

                    for (int i = 0; i < this->p_noOfPSpots; i++) {
                        if (this->p_parkingSpots[i] == nullptr) {

                            this->p_parkingSpots[i] = newVehilce2;
                            this->p_parkingSpots[i]->setParkingSpot(i + 1);

                            cout << endl << "Parking Ticket" << endl;
                            newVehilce2->write(cout);

                            this->p_noOfParkedVehicles++;
                          


                        }
                    }
                   
                    cout << endl;
                    cout << "Press <ENTER> to continue...." << endl;
                    
                }
                break;
               
                case 3: 
                    
                    cout << "Cancelled parking" << endl;
                   
                    cout << endl;
                    break; 
                default:
                     break;
            }
        }

    }




    void Parking::returnVehicle()
    {

        char findplate[9];

        int flag2 = false;
        bool vehicleFound = false;

        int matchIndex;
        
        cout << "Return Vehicle" << endl;
        cout << "Enter License Plate Number: ";

        do
        {

            cin >> findplate;
            cin.clear();

            if (strlen(findplate) < 1 || strlen(findplate) > 8)
            {
                cout << "Invalid License Plate, try again: ";
                cin.clear();
            }
            else
            {
                flag2 = true;
            }
        } while (flag2 == false);

        cout << endl;
        toUpperCase(findplate);

        for (int i = 0; i < this->p_noOfPSpots; i++) {
            if (this->p_parkingSpots[i] != nullptr) {
                if (strcmp(this->p_parkingSpots[i]->getLicensePlate(), findplate) == 0) {
                    vehicleFound = true;
                    matchIndex = i;
                }

            }
        }
        if (vehicleFound) {
            cout << "Returning:" << endl;
            this->p_parkingSpots[matchIndex]->setCsv(false);
            this->p_parkingSpots[matchIndex]->write(cout);


            delete this->p_parkingSpots[matchIndex];    
             this->p_parkingSpots[matchIndex]= nullptr;

            this->p_noOfParkedVehicles--;

            cout << endl;

        }
        else {
            cout << "License plate " << toUpperCase(findplate) << " Not found" << endl << endl;;

        }
        cout << "Press <ENTER> to continue...." << endl;

      
        

    }


    void Parking::parkListVehicle()const
    {
        cout << "*** List of parked vehicles ***" << endl;
        for (int i = 0; i < this->p_noOfPSpots; i++) {
            if (this->p_parkingSpots[i] != nullptr) {

                this->p_parkingSpots[i]->setCsv(false);
                this->p_parkingSpots[i]->write(cout);

                    cout << "-------------------------------" << endl;
            }
        }
        cout << "Press <ENTER> to continue...." << endl;
    }


    void Parking::findVehicle()
    {
        char findplate[9];

        int flag2 = false;
        bool vehicleFound = false;

        int matchIndex;

        cout << "Vehicle Search" << endl;
        cout << "Enter Licence Plate Number: ";

        do
        {

            cin >> findplate;
            cin.clear();

            if (strlen(findplate) < 1 || strlen(findplate) > 8)
            {
                cout << "Invalid License Plate, try again: ";
                cin.clear();
            }
            else
            {
                flag2 = true;
            }
        } while (flag2 == false);

        cout << endl;
        toUpperCase(findplate);

        for (int i = 0; i < this->p_noOfPSpots; i++) {
            if (this->p_parkingSpots[i] != nullptr) {
                if (strcmp(this->p_parkingSpots[i]->getLicensePlate(), findplate) == 0) {
                    vehicleFound = true;
                    matchIndex = i;
                }
                   
            }
        }
          if(vehicleFound){
                cout << "Vehicle found:" << endl;

                this->p_parkingSpots[matchIndex]->setCsv(false);
                this->p_parkingSpots[matchIndex]->write(cout);
               
                cout << endl;

            }
            else {
              cout << "License plate " << toUpperCase(findplate) << " Not found" << endl << endl;;

            }
          cout << "Press <ENTER> to continue...." << endl;

    }
    bool Parking::closeParking()
    {
        bool returnValue = false;
        char input;
        int flag = 0;

        if (isEmpty()) {
            cout << "Close Parking" << endl;
            return true; 
        }
        else {
            cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
            cout << "Are you sure? (Y)es/(N)o: ";
            
           


            for (int i = 0; flag == 0; i++)
            {
                cin >> input;
                if (input == 'Y' || input == 'y')
                {

                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Closing Parking" << endl;
                    cout << endl;

                    for (int i = 0; i < this->p_noOfPSpots; i++) 
                    {

                        if (this->p_parkingSpots[i] != nullptr) 
                        {
                            cout << "Towing request" << endl;
                            cout << "*********************" << endl;

                            this->p_parkingSpots[i]->setCsv(false);
                            this->p_parkingSpots[i]->write(cout);

                          
                            delete this->p_parkingSpots[i];
                            this->p_parkingSpots[i] = nullptr;
                            
                            this->p_noOfParkedVehicles--;

                           
                            if (i < this->p_noOfPSpots - 1)
                            {
                                cout << endl;
                            }

                        }
                    }

                    returnValue = true;
                    flag = 1;
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

        }
        return returnValue;
    }

    bool Parking::exitParking()const
    {
        cout << "This will terminate the program!" << endl;
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
                cout << "Exiting program!" << endl;
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



    bool Parking::loadDataFile()
    {
         bool loadStatus = false;

        char vehicleType;

        Vehicle* vehicle{};

        if (!isEmpty()) {

            ifstream file(this->p_filename);

            if (!file) {                                                                    
                loadStatus = true; 
            }
            else {
               
                while (!file.eof()) {                                                   
                   vehicleType= file.get();                                             
                   file.ignore();

                   if (vehicleType == 'M') {
                       vehicle = new Motorcycle;

                       vehicle->setCsv(true);
                       vehicle->read(file);                                            
                       if (!file.fail()) {                                             
                      
                          
                           this->p_parkingSpots[ vehicle->getParkingSpot() - 1] = vehicle;                

                           this->p_noOfParkedVehicles++;                                

                         
                       }
                       else
                       {
                           delete vehicle;
                           loadStatus = false;
                      
                       }
                   }

                   
                   else if (vehicleType == 'C') {
                       vehicle = new Car;

                       vehicle->setCsv(true);
                       vehicle->read(file);                                             

                       if (!file.fail()) {

                          
                           this->p_parkingSpots[  vehicle->getParkingSpot() - 1] = vehicle;

                           this->p_noOfParkedVehicles++;


                       }
                       else
                       {
                           delete vehicle;
                           loadStatus = false;

                       }
                   }


                }
                loadStatus = true; 
                
            }
            file.close();
           
        }
       
        return loadStatus;
    }


    void Parking::savaDataFile()const
    {
        ofstream file(this->p_filename);
        if (file) {
            for (int i = 0; i < this->p_noOfPSpots; i++) {
                if (this->p_parkingSpots[i] != nullptr) {

                    this->p_parkingSpots[i]->setCsv(true);
                    this->p_parkingSpots[i]->write(file);
                }
            }
        }
        file.close();
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



