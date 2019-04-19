/* 
File Name: namesScores.cpp
Author: Esther Heralta Espinosa
Date: 04/17/19
Description of the program: Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, 
                            begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value 
                            by its alphabetical position in the list to obtain a name score.
	
			    For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th 
			    name in the list. So, COLIN would obtain a score of 938 × 53 = 497    
			    What is the total of all the name scores in the file?
*/

#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

const int NOT_FOUND = 9999;

string getFileContent (const string& fileName) {
	//stores in a string the content of the file and returns the string
	ifstream inputFile;
	string auxStr = "";

	inputFile.open(fileName);
	if (inputFile.fail()) {
		cout << "Error opening " << fileName << endl;
		exit(1);
	}
	else {
		while (!inputFile.eof()) {
			inputFile >> auxStr;
		}
	}

	inputFile.close();

	return (auxStr);

}

vector<string> initializeVectorWithNames (const string& nameFile, vector<string>& aVector) {
	//read the content of the file and store it into the vector
	string fileContent = getFileContent(nameFile);

	//cout << fileContent << endl;

	//removes the character " from the string fileContent
	fileContent.erase(remove(fileContent.begin(), fileContent.end(), '"'), fileContent.end());

	//cout << fileContent << endl;
	
	int pos = 0;
	string aux = "";

	while (pos < fileContent.length()) {		
		while (fileContent[pos] != ',') {
			aux.insert(aux.end(), fileContent[pos]);
		 	pos++;
		}
		aVector.push_back(aux);
		//cout << endl << "aux: " << aux << endl;
		pos++;
		aux = "";
		//cout << endl << "aux: " << aux << endl;
	}

	return (aVector);
}

void printOutVector (vector<string>& aVector) {
	//displays the size and its content
	vector<string>::iterator ite; 
	cout << "Vector content: " << endl;
	for (ite = aVector.begin(); ite < aVector.end(); ite++) {
		cout << *ite << " - ";
	}
	cout << endl << aVector.size() << endl;
}

void printOutArray (const char anArray[], const int& sizeArray) {
	//displays the content of the given array
	cout << "Array content: " << endl;
	for (int index = 1; index < sizeArray - 1; index++) {
		cout << anArray[index] << ", ";
	}
}

int getScoreOfAGivenName (const char anArray[], const int& sizeArray, const int& positionNameInVector, const string& name) {
	//working out the alphabetical value for each name, multiply this value 
    //by its alphabetical position in the list to obtain a name score
    //example: ABBA = 1 + 2 + 2 + 1 = 6
    //         let's imagine that ABBA is in the 10th position => score = 6 * 10 = 60

	int totalName = 0;
	for (int index = 0; index < name.length(); index++) {
		for (int indexArray = 0; indexArray < sizeArray; indexArray++) {
			if (name[index] == anArray[indexArray]) {
				totalName = totalName + indexArray;
			}
		}
	}

	return (totalName * positionNameInVector);
}

int findNamePosition (vector<string>& aVector, const string& aName) {
	//retruns the position of a given name in the vector
	
	//if (aVector.find(aVector.begin(), aVector.end(), aName) != aVector.end()) 

	// Check if a given name exists in vector
	vector<string>::iterator it = find(aVector.begin(), aVector.end(), aName);
 
	if (it != aVector.end()) {
		//cout << "Name Found." << endl;
 
		// Get index of name from iterator
		int index = distance(aVector.begin(), it);
		//cout <<"Index of name in vector : " << index << endl;
		return (index);
	}
	else {
		return (NOT_FOUND);
	}
}

void totalAllNamesScore (const char anArray[], const int& sizeArray, vector<string>& aVector) {
	//displays the total of all the name scores 
	int totalScore = 0;
	int position = 0;
	vector<string>::iterator ite; 

	for (ite = aVector.begin(); ite < aVector.end(); ite++) {
		position = findNamePosition(aVector, *ite) != NOT_FOUND;
		if (position != NOT_FOUND) {
			totalScore = totalScore + getScoreOfAGivenName(anArray, sizeArray, position, *ite);
		}
	}

	cout << endl << "Total of all the names score: " << totalScore << endl << endl;
}


int main () {
	vector<string> namesVector;
	//A is in the first position, B is in the second position, ...
	char alphabetArray [] = "*ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	namesVector = initializeVectorWithNames("names.txt", namesVector);
	//sorting the vector into alphabetical order
	sort(namesVector.begin(), namesVector.end()); 
	
	totalAllNamesScore(alphabetArray, 28, namesVector);
}
