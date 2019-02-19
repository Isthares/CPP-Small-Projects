#include "file.h"

//constructor
File::File() {}

//Add Records
void File::addRecords() {

    //system("clear"); //clear screen

    Menu m;
    Student s;
    char opt;

    //let the user enter information (name, last name, id, major, # of courses)
    s = m.getAddedRecord (); 
    //cout << s.getStudentID() << ", " << s.getStudentName() << ", " << s.getStudentLastName() << ", " << s.getStudentMajor() << ", " << s.getNumCourses() << endl;

    //add the new record to the file 
    //- open the file 
    dataFile.open("studentDBFile.txt", ios::app); //ios::app >> All output operations are performed at the end of the file, 
    											  //			appending the content to the current content of the file
    //- check if the file is in failed state
    if (dataFile.fail()) {
    	cout << "Error opening studentDBFile.txt." << endl;
    }
    else {
    	//- write to the file the record
	    dataFile << s.getStudentID() << "**" << s.getStudentName() << "**" << s.getStudentLastName() << "**" << s.getStudentMajor() << "**" << s.getNumCourses() << "\n";
        m.addedRecordMessage (s.getStudentName(), s.getStudentLastName());

	    //prompt user whether wants to add another record or not
	    opt = m.addNewRecord ();
	    //check that the option entered is valid (Y / N)
	    opt = m.getValidAddNewRecordOption (opt); 

	    while (opt == 'Y') { //while the user wants to add a new record
	    	//let the user enter information (name, last name, id, major, # of courses)
	    	s = m.getAddedRecord ();
	    	//cout << s.getStudentID() << ", " << s.getStudentName() << ", " << s.getStudentLastName() << ", " << s.getStudentMajor() << ", " << s.getNumCourses() << endl;

	    	//add the new record to the file
	    	dataFile << s.getStudentID() << "**" << s.getStudentName() << "**" << s.getStudentLastName() << "**" << s.getStudentMajor() << "**" << s.getNumCourses() << "\n";
	    	m.addedRecordMessage (s.getStudentName(), s.getStudentLastName());

	    	//prompt user whether wants to add another record (Y) or not (N)
	    	opt = m.addNewRecord ();
	    	opt = m.getValidAddNewRecordOption (opt);
	    }

	    //close the file
	    dataFile.close();

	    //return to main menu
    }
}

//extract the student's data from the file
Student File::extractStudentInfoFromFile (string studentInformation) {
	Student s;

	string delimiter = "**";
	int pos = 0;
	string copy = studentInformation;
	string temp = "";

	//find(const string& str, size_t pos = 0) 
	//  >> it returns the position of the first occurrence of str in the string, or npos if the string is not found
	//substr(size_t pos = 0, size_t n = npos)
	//  >> it returns a substring of the object, starting at position pos and of length npos
	//If you have multiple delimiters, after you have extracted one token, you can remove it (delimiter included) 
	//to proceed with subsequent extractions >> copy = copy.substr(pos + delimiter.length());


	//string format in the file: ID**name**lastName**major**courses\n
	//get student's ID
	pos = copy.find(delimiter);
	s.setStudentID(copy.substr(0, pos));
	copy = copy.substr(pos + delimiter.length());

	//get student's name
	pos = copy.find(delimiter);
	s.setStudentName(copy.substr(0, pos));
	copy = copy.substr(pos + delimiter.length());

	//get student's last name
	pos = copy.find(delimiter);
	s.setStudentLastName(copy.substr(0, pos));
	copy = copy.substr(pos + delimiter.length());

	//get student's major
	pos = copy.find(delimiter);
	s.setStudentMajor(copy.substr(0, pos));
	copy = copy.substr(pos + delimiter.length());

	//cout << "copy: " << copy << endl;
	//get student's courses
	int courses = stoi(copy);
	s.setStudentCourses(courses);

	return (s);
}

//checks if the file that contains the records is empty
bool File::isFileEmpty () {
	dataFile.seekg (0, ios::end); //put the "cursor" at the end of the file
	int length = dataFile.tellg(); ///find the position of the cursor
	if (length == 0) {
		return (true);
	}
	else {
		return (false);
	}
}

//List Records
void File::listRecords() {
	string line = "";
	Student s;
	Menu m;

	//open file
	dataFile.open("studentDBFile.txt", ios::in);
	
	//check if the file exist
	if(!dataFile) {
		cout << endl;
		cout << "           The file does not exist. " << endl;
	}
	//- check if the file is in failed state
    else if (dataFile.fail()) {
    	cout << endl;
    	cout << "           Error opening studentDBFile.txt." << endl;
    }
    else {
    	//checks if the file that contains the records is empty
    	if (isFileEmpty()) {
    		cout << endl << endl;
    		cout << "           ******************** LIST RECORDS ********************" << endl << endl;
    		cout << "                     There are no records in the system. " << endl << endl;
    		cout << "           ******************************************************" << endl;
    	}
    	else {
    		//read file's content and display it on screen
    		dataFile.seekg (0, ios::beg); //put the "cursor" at the beginning of the file
	    	cout << endl << endl;
	    	cout << "           ******************** LIST RECORDS ********************" << endl << endl;
			while (getline(dataFile,line)) { //is True only only while there is something to read. Works nicely as an end of file check
				
				s = extractStudentInfoFromFile (line);
				m.displayAddedRecords (s);
			}
			cout << "           ******************************************************" << endl;
    	}
    	//close file
		dataFile.close();
    }
}


//check if the student id entered by the user exist in the file
bool File::isIDInFile(string studentID) {
	//string format in the file: ID**name**lastName**major**courses\n 

	string delimiter = "**";
	string line = ""; 
	string currentStudentID = "";
	int pos = 0;

	//cout << "id to delete: " << studentID << endl;

	//open data file
	dataFile.open("studentDBFile.txt", ios::in);
	
	if (dataFile.fail()) {
    	cout << "           isIDInFile: Error opening studentDBFile.txt." << endl;
    }
    else {
    	dataFile.seekg (0, ios::beg); //put the "cursor" at the beginning of the file
    	while (getline(dataFile,line)) { 
		//	cout << "line: " << line << endl;
			pos = line.find(delimiter);
			currentStudentID = line.substr(0, pos);

		//	cout << "currentStudentID: " << currentStudentID << endl;

			if (studentID.compare(currentStudentID) == 0) {
			//	cout << "id in the file" << endl;
				return (true);
			}
			pos = 0;
		}

		//close data file
		dataFile.close();
    }
	return (false);
}

//delete from the system a valid student entered by the user
void File::deleteValidRecord (string studentID) {
	Menu m;
	fstream tmp;
	string line = ""; 
	string currentStudentID = "";
	int pos = 0;
	string delimiter = "**";

	//open the file 
	dataFile.open("studentDBFile.txt");
	
    tmp.open("temporal.txt", ios::out);
    
    //check if the file is in failed state
    if (tmp.fail()) {
    	cout << endl << "           Error opening temporal.txt." << endl << endl;
    }
    else if (dataFile.fail()) {
    	cout << endl << "           deleteValidRecord: Error opening studentDBFile.txt." << endl << endl;
    	//close the file
	    tmp.close();
    }
    else {
    	dataFile.seekg (0, ios::beg); //put the "cursor" at the beginning of the file
    	tmp.seekg (0, ios::beg); //put the "cursor" at the beginning of the file
    	while (getline(dataFile, line)) { 
    		//cout << line << endl;
    		pos = line.find(delimiter);
			currentStudentID = line.substr(0, pos);
			//cout << currentStudentID << ", " << studentID << endl;
			if (studentID.compare(currentStudentID) != 0) {
				tmp << line << endl;
				cout << "line to write in tmp: " << line << endl;
			}
			pos = 0;
			getchar();
   		}

    	m.deletedRecordMessage (studentID);

    	//close the file
	    tmp.close();

	    //close the file
		dataFile.close();

		remove("studentDBFile.txt");
		rename("temporal.txt","studentDBFile.txt");
    }
}

//Delete Records
void File::deleteRecords(){
	Menu m;
	char opt;
	Student s;
	string idToDelete = "";

    //let the user enter the student id to delete
    idToDelete = m.getDeleteRecord ();

	//check that the id entered exist in the file
	if (isIDInFile(idToDelete)) {
		//delete the record
		deleteValidRecord (idToDelete);
	}
	else {
		m.notValidStudentIDMessage(idToDelete);
	}

	//prompt user whether wants to delete another record (Y) or not (N)
	opt = m.deleteRecord ();
	opt = m.getValidDeleteRecordOption (opt);

	while (opt == 'Y') { //while the user wants to delte a record

		//let the user enter the student id to delete
		idToDelete = m.getDeleteRecord ();

		//check that the id entered exist in the file
    	if (isIDInFile(idToDelete)) {
    		//delete the record
    		deleteValidRecord (idToDelete);
    	}
    	else {
    		m.notValidStudentIDMessage(idToDelete);
    	}

    	//prompt user whether wants to delete another record (Y) or not (N)
		opt = m.deleteRecord ();
		opt = m.getValidDeleteRecordOption (opt);
	}

}
