//  Esther Heralta Espinosa
//  02/13/19
//
//  Created by Esther Heralta Espinosa on 13/02/2019.
//  Copyright © 2019 Esther Heralta Espinosa. All rights reserved.

#pragma once

#include "menu.h"

#include <fstream>
#include <stdlib.h> //clear screen: system("clear")
#include <cstdio> //getchar()

class File {

	private:
		fstream dataFile;

	public:
		File();
		//Add Records
		void addRecords();
		//checks if the file that contains the records is empty
		bool isFileEmpty ();
		//List Records
		void listRecords();
    	//Delete Records
    	void deleteRecords();
    	//extract the student's data from the file
    	Student extractStudentInfoFromFile (string studentInformation);
    	//check if the student id entered by the user exist in the file
		bool isIDInFile(string studentID);
		//delete from the system a valid student entered by the user
		void deleteValidRecord (string studentID);
};
