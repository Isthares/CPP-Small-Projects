//  Esther Heralta Espinosa
//  02/13/19
//
//  Created by Esther Heralta Espinosa on 13/02/2019.
//  Copyright © 2019 Esther Heralta Espinosa. All rights reserved.

//#ifndef MENU_H
//#define MENU_H

#pragma once

#include <iostream>
using namespace std;
#include <stdlib.h> //clear screen: system("clear")
#include "student.h"

class Menu {
    public:     
        Menu(); //constructor
        void displayMainMenu (); //display the Main Menu
        char chooseOption (); //the user choose an option of the main menu
        bool isValidOption (char opt);  //check wheter the option chosen by the user is valid (return true) or not (return false)
        char getValidOption (); //the user choose a valid option of the main menu
        Student getAddedRecord (); //display Add Record Menu and store the entered record in a student object  
        void addedRecordMessage (string name, string lastName); //display a message with the name and last name of the student added
        char addNewRecord (); //prompt the user if he/she wants to add a new record to the database
        char getValidAddNewRecordOption (char yesOrNo); //check if the user has chosen a valid option (Y/N)
        void displayAddedRecords (Student s); //display the record information of a student
        char deleteRecord (); //prompt the user if he/she wants to delete a record from the database
        char getValidDeleteRecordOption (char yesOrNo); //check if the user has chosen a valid option (Y/N)       
        void deletedRecordMessage (string studentID); //display a message with the id of the student deleted
        string getDeleteRecord (); //display Delete Record Menu and get the student id of the student that the user wants to delete
        void notValidStudentIDMessage (string studentID); //display a message of not valid student id
        void emptyFileMessage (); //display a message of file is empty
};

//#endif
