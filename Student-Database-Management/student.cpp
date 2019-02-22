//  Esther Heralta Espinosa
//  02/13/19
//
//  Created by Esther Heralta Espinosa on 13/02/2019.
//  Copyright © 2019 Esther Heralta Espinosa. All rights reserved.

#include "student.h"

//constructor
Student::Student() {
	studentID = "";
	name = "";
	lastName = "";
	major = "";
	numCourses = 0;
}

//get the student ID
string Student::getStudentID() {
	return (studentID);
}

//get the name of the student
string Student::getStudentName()  {
	return (name);
}

//get the lastname of the student
string Student::getStudentLastName() {
	return (lastName);
}

//major pursued
string Student::getStudentMajor() {
	return (major);
}

//# of courses
int Student::getNumCourses() {
	return (numCourses);
}

//modify studentID
void Student::setStudentID(string aStudentID) {
	studentID = aStudentID;
}

//modify student's name
void Student::setStudentName(string aName) {
	name = aName;
}

//modify student's lastname
void Student::setStudentLastName(string aLastName) {
	lastName = aLastName;
}

//modify student's courses
void Student::setStudentCourses(int nCourses) {
	numCourses = nCourses;
}

//modify student's major
void Student::setStudentMajor(string aMajor) {
	major = aMajor;
}	
