//  Esther Heralta Espinosa
//  02/13/19
//
//  Created by Esther Heralta Espinosa on 13/02/2019.
//  Copyright © 2019 Esther Heralta Espinosa. All rights reserved.

#include "menu.h"

//constructor
Menu::Menu() {} 

//display the Main Menu
void Menu::displayMainMenu () {
    //system("clear"); //clear screen
    cout << endl << endl;
    cout << "           ****** STUDENT DATABASE MANAGEMENT MENU ******" << endl << endl;
    cout << "                   1. Add    Records" << endl;
    cout << "                   2. List   Records" << endl;
    cout << "                   3. Delete Records" << endl;
    cout << "                   4. Exit   Program" << endl << endl;
    cout << "           **********************************************" << endl;
}

//the user choose an option of the main menu
char Menu::chooseOption () {
    char option;
    cout << endl << "           Choose an option: ";
    cin >> option;
    return (option);
}

//check wheter the option chosen by the user is valid (return true) or not (return false)
bool Menu::isValidOption (char opt) {
    if ((opt == '1') || (opt == '2' ) || (opt == '3' ) || (opt == '4' )) {
        return (true);
    }
    else {
        return (false);
    }
}

//the user choose a valid option of the main menu
char Menu::getValidOption () {
    char option = chooseOption();
    while (!isValidOption(option)) {
        cout << "           Invalid choice. Please, choose a valid one." << endl;
        option = chooseOption();
    }
    return (option);
}

//display Add Record Menu and store the entered record in a student object
Student Menu:: getAddedRecord () {
    Student s;
    string tmp = "";
    int courses;

    cout << endl << endl;
    cout << "           ******************** ADD RECORDS ********************" << endl << endl;
    cout << "                  · Enter student Name: ";
    cin >> tmp;
    s.setStudentName(tmp);
    cout << "                  · Enter student Last Name: ";
    cin.ignore(); //to flush the newline out of the buffer in between
    getline(cin, tmp);
    s.setStudentLastName(tmp);
    cout << "                  · Enter student ID: ";
    cin >> tmp;
    s.setStudentID(tmp);
    cout << "                  · Enter number of courses that the student takes: ";
    cin >> courses;
    s.setStudentCourses(courses);
    cout << "                  · Enter student Major: ";
    cin.ignore(); //to flush the newline out of the buffer in between
    getline(cin, tmp);
    s.setStudentMajor(tmp);
    cout << endl;   
    cout << "           *****************************************************" << endl;

    return (s);
}

//display a message with the name and last name of the student added
void Menu::addedRecordMessage (string name, string lastName) {
    //transfrom >> transform a string to uppercase
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    transform(lastName.begin(), lastName.end(), lastName.begin(), ::toupper);

    cout << endl << "           The student: " << name << " " << lastName << " has been added to the system. " << endl << endl;
}

//prompt the user if he/she wants to add a new record to the database
char Menu::addNewRecord () {
    char opt;
    cout << "           Do you want to add another record?  (Y/N)  >>>  ";
    cin >> opt;
    opt = toupper(opt);
    return (opt);
}

//check if the user has chosen a valid option (Y/N)
char Menu::getValidAddNewRecordOption (char yesOrNo) {
    while ((yesOrNo != 'Y') && (yesOrNo != 'N')) {
        cout << "           Invalid choice. Please, try it again." << endl << endl;
        yesOrNo = addNewRecord ();
    }
    return (yesOrNo);
}

//display the record information of a student
void Menu::displayAddedRecords (Student s) {
    cout << "                  Student: " << s.getStudentName() << " " << s.getStudentLastName() << endl;
    cout << "                   · ID: " << s.getStudentID() << endl;
    cout << "                   · Major: " << s.getStudentMajor() << endl;
    cout << "                   · Number of courses: " << s.getNumCourses() << endl << endl;
}

//prompt the user if he/she wants to delete a record from the database
char Menu::deleteRecord () {
    char opt;
    cout << "           Do you want to delete a record?  (Y/N)  >>>  ";
    cin >> opt;
    opt = toupper(opt);
    return (opt);
}

//check if the user has chosen a valid option (Y/N)
char Menu::getValidDeleteRecordOption (char yesOrNo) {
    while ((yesOrNo != 'Y') && (yesOrNo != 'N')) {
        cout << "           Invalid choice. Please, try it again." << endl << endl;
        yesOrNo = deleteRecord ();
    }
    return (yesOrNo);
}

//display a message with the id of the student deleted
void Menu::deletedRecordMessage (string studentID) {
    //transfrom >> transform a string to uppercase
    transform(studentID.begin(), studentID.end(), studentID.begin(), ::toupper);

    cout << endl << "           The student with the ID: " << studentID << " has been deleted from the system. " << endl << endl;
}

//display Delete Record Menu and get the student id of the student that the user wants to delete
string Menu:: getDeleteRecord () {
    string studentID = "";

    cout << endl << endl;
    cout << "           ******************** DELETE RECORDS *****************" << endl << endl;
    cout << "                  · Enter student ID: ";
    cin >> studentID;
    cout << endl;   
    cout << "           *****************************************************" << endl;

    return (studentID);
}

//display a message of not valid student id
void Menu::notValidStudentIDMessage (string studentID) {
    cout << endl << "           The student with the ID: " << studentID << " does not exist in the system. " << endl << endl;
}

//display a message of file is empty
void Menu::emptyFileMessage () {
    cout << endl << "           The file is empty. There are no records to delete. " << endl << endl;
}
