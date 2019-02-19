#pragma once

#include <string>
#include <iostream>
using namespace std;

class Student {

	private:
		string studentID; //student's id
		string name; //student's name
		string lastName; //student's last name
		string major; //major pursued
		int numCourses; //number of courses that the student is taken

	public:
		//constructor
		Student(); 

		//get the student ID
		string getStudentID();
		//get the name of the student
		string getStudentName();
		//get the lastname of the student
		string getStudentLastName();
		//major pursued
		string getStudentMajor();
		//# of courses
		int getNumCourses();

		//modify studentID
		void setStudentID(string aStudentID);
		//modify student's name
		void setStudentName(string aName);
		//modify student's lastname
		void setStudentLastName(string aLastName);
		//modify student's courses
		void setStudentCourses(int courses);
		//modify student's major
		void setStudentMajor(string aMajor);

		//string& accessName() const {return &name;}
};
