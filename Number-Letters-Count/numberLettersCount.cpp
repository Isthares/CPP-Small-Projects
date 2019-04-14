/* 
File Name: numberLetterCounts.cpp
Author: Esther Heralta Espinosa
Date: 04/08/19
Description of the program: If the numbers 1 to 5 are written out in words:
    			    one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

			    Display: The number in digits, the number in written letters, and the number of letters us    
			    Display: If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, 
			    		 how many letters would be used?
			    
			    NOTE: Do not count spaces or hyphens. For example:
				  342 (three hundred and forty-two) contains 23 letters
				  115 (one hundred and fifteen) contains 20 letters
*/

#include <iostream>
using namespace std;
#include <string>
#include <map>


const char SPACE = ' ';
const char HYPHON = '-';
const string SPACE_HYPHON_SPACE = " - ";
const string SPACE_AND_SPACE = " and ";


int getNumberOfLettersString(string& number) {
	//returns the number of letters of a given string (without counting spaces or hyphons)
	int count = 0;
	for (int i = 0; i < number.length(); i++) {
		if ((number[i] != SPACE) && (number[i] != HYPHON)) {
			count++;
			//cout << number[i] << ", " << count << endl;
		}
	}
	return (count);
}

int getNumberOfLettersMap(map<string, string>& numbers){
	/*
	returns the number of letters from a given dict of numbers
	if numbers = {1:"one",2:"two",3:"three"} then returns 11
	*/
	int count = 0;
	map<string, string>::iterator itr; //iterator for map
	for(itr = numbers.begin(); itr != numbers.end(); itr++){
		//cout << "key: " << itr->first << ", value: " << itr->second << endl;
		count = count + (itr->second).length();
	}

	return (count);
}

bool isNumberInMap(string& num, map<string, string>& aMap) {
	//returns true if the number num is in the map aMap, False othewise
	//if num == 7 then returns true
	//if num == 27 then returns false
	map<string, string>::iterator itr; //iterator for map
	bool exist = false;
	for(itr = aMap.begin(); itr != aMap.end(); itr++){
		//if (itr->first == num) {
		if (itr->first.compare(num) == 0) {
			exist = true;
			break;
		}
	}
	return (exist);
}

string getTenToNineteenWrittenNumber(map<string, string>& aMap, string& num) {
	// returns a written number between the range of ten and nineteen
	string writtenNumber = "";
	int secondNumber = 0;
	
	if (num.length() == 2) {
		secondNumber = (int)(num[1]) - 48;
	}
	else if (num.length() == 3) {
		secondNumber = (int)(num[2]) - 48;
	}

	switch(secondNumber) {
		case 0: writtenNumber = aMap["10"];
				break;
		case 1: writtenNumber = aMap["11"];
				break;
		case 2: writtenNumber = aMap["12"];
				break;
		case 3: writtenNumber = aMap["13"];
				break;
		case 4: writtenNumber = aMap["14"];
				break;
		case 5: writtenNumber = aMap["15"];
				break;
		case 6: writtenNumber = aMap["16"];
				break;
		case 7: writtenNumber = aMap["17"];
				break;
		case 8: writtenNumber = aMap["18"];
				break;
		case 9: writtenNumber = aMap["19"];
				break;
		default: break;
	}

	return (writtenNumber);
}

string generateTensWrittenNumber(map<string, string>& aMap, string& num) {
	//returns a string with a digit
	//if 2 then returns twenty
	//if 7 then returns seventy
	string writtenNumber = "";
	int firstNumber = 0;

	if (num.length() == 2) {
		firstNumber = (int)(num[0]) - 48;
	}
	else if (num.length() == 3) {
		firstNumber = (int)(num[1]) - 48;
	}
	
	switch(firstNumber){
		case 1: writtenNumber = getTenToNineteenWrittenNumber(aMap, num);
				break;
		case 2: writtenNumber = aMap["20"];
				break;
		case 3: writtenNumber = aMap["30"];
				break;
		case 4: writtenNumber = aMap["40"];
				break;
		case 5: writtenNumber = aMap["50"];
				break;
		case 6: writtenNumber = aMap["60"];
				break;
		case 7: writtenNumber = aMap["70"];
				break;
		case 8: writtenNumber = aMap["80"];
				break;
		case 9: writtenNumber = aMap["90"];
				break;
		default: break;
	}
	
	return (writtenNumber);
}

string generateOnesWrittenNumber(map<string, string>& aMap, string& num) {
	//returns a string with two digits
	// if 28 then returns twenty - eight
	// if 34 then returns thirty - four
	string writtenNumber = "";
	int firstNumber = 0;

	if (num.length() == 1) {
		firstNumber = (int)(num[0]) - 48;
	}
	else if (num.length() == 2) {
		firstNumber = (int)(num[1]) - 48;
	}
	else if (num.length() == 3) {
		firstNumber = (int)(num[2]) - 48;
	}


	switch(firstNumber){
		case 1: writtenNumber = aMap["1"];
				break;
		case 2: writtenNumber = aMap["2"];
				break;
		case 3: writtenNumber = aMap["3"];
				break;
		case 4: writtenNumber = aMap["4"];
				break;
		case 5: writtenNumber = aMap["5"];
				break;
		case 6: writtenNumber = aMap["6"];
				break;
		case 7: writtenNumber = aMap["7"];
				break;
		case 8: writtenNumber = aMap["8"];
				break;
		case 9: writtenNumber = aMap["9"];
				break;
		default: break;
	}
	return (writtenNumber);
}

bool isTenInMap(string& num) {
	//returns true if last two digits of num are: 10, 11, 12, 13, 14, ..., 19, 20, 30, 40, 50, 60, 70, 80, or 90

	if ((num.compare("10") == 0) || (num.compare("11") == 0) || (num.compare("12") == 0) || (num.compare("13") == 0) || (num.compare("14") == 0) || 
		(num.compare("15") == 0) || (num.compare("16") == 0) || (num.compare("17") == 0) || (num.compare("18") == 0) || (num.compare("19") == 0) || 
		(num.compare("20") == 0) || (num.compare("30") == 0) || (num.compare("40") == 0) || (num.compare("50") == 0) || (num.compare("60") == 0) || 
		(num.compare("70") == 0) || (num.compare("80") == 0) || (num.compare("90") == 0)) {
		return (true);
	}
	else {
		return (false);
	}
}

string generateTwoDigitWrittenNumber(map<string, string>& aMapNumbers, string& number) {
	//returns the written number of the given number 
	//if number = "27" then returns twenty - seven
	string writtenNumber = generateTensWrittenNumber(aMapNumbers, number);

	//cout << number.length() << ", " << number[1] << endl;
	if ((number.length() == 3) && (number[1] == '0')) {
		//101, 102, 103, 104, 105, 106, 107, 108, 109, 201, 202, 203, 204, ..., 908, 909
		//cout << writtenNumber << endl;
		writtenNumber = writtenNumber + generateOnesWrittenNumber(aMapNumbers, number);
	}
	else if ((number.length() == 3) && (number[1] != '0')) {
		string aux = number.substr(1,2);

		if (!isTenInMap(aux)) {
			writtenNumber = writtenNumber + SPACE_HYPHON_SPACE + generateOnesWrittenNumber(aMapNumbers, number);
		}
	}
	else {
		writtenNumber = writtenNumber + SPACE_HYPHON_SPACE + generateOnesWrittenNumber(aMapNumbers, number);
	}
	
	return (writtenNumber);
}

string generateHundredsWrittenNumber(map<string, string>& aMap, string& number) {
	//returns a string with one digit
	// if "100" then returns one hundred
	// if "400" then return four hundred
	string writtenNumber = "";
	int thirdNumber = (int)(number[0]) - 48;
	switch(thirdNumber){
		case 1: writtenNumber = aMap["100"];
				break;
		case 2: writtenNumber = aMap["200"];
				break;
		case 3: writtenNumber = aMap["300"];
				break;
		case 4: writtenNumber = aMap["400"];
				break;
		case 5: writtenNumber = aMap["500"];
				break;
		case 6: writtenNumber = aMap["600"];
				break;
		case 7: writtenNumber = aMap["700"];
				break;
		case 8: writtenNumber = aMap["800"];
				break;
		case 9: writtenNumber = aMap["900"];
				break;
		default: break;
	}
	return (writtenNumber);
}

string generateThreeDigitWrittenNumber(map<string, string>& aMapNumbers, string& number) {
	//returns the written number of the given number 
	//if number = "270" then returns two hundred and seventy
	//if number = "646" then returns  six hundred and fourty - six

	string writtenNumber = generateHundredsWrittenNumber(aMapNumbers, number);

	writtenNumber = writtenNumber + SPACE_AND_SPACE + generateTwoDigitWrittenNumber(aMapNumbers, number);
	

	return (writtenNumber);
}

string generateWrittenNumber(map<string, string>& numbers, string& number){
	//returns the written number of the given number
	//if number = 7 then returns seven
	if (isNumberInMap(number, numbers)) {
		return (numbers[number]); //returns the value
	}
	else{
		//generate the written number and stores it in the map
		string writtenNumber = "";
		switch (number.length()) {
			case 2: writtenNumber = generateTwoDigitWrittenNumber(numbers, number);
					break;
			case 3: writtenNumber = generateThreeDigitWrittenNumber(numbers, number);
					break;
		}
		return (writtenNumber);
	}
}

bool validateDataEntered(int& number) {
	//return true if the number entered by the use is in the range: 1 to 1000
	if ((number >= 1) && (number <= 1000)) {
		return (true);
	}
	else {
		return (false);
	}
}

int getValidNumber(int& num) {
	//ask the user to enter a valid number in case the number entered is not correct
	//returns a valid number

	while (!validateDataEntered(num)){
		cout << endl;
		cout << "The number entered is not valid. Please, try it again." << endl;
		cout << endl << "Enter a number between 1 and 1000: ";
		cin >> num;
	}

	return (num);
}

map<string, string> createOneToNineteenMap() {
	//creates a map that contains: key = number, value = number written and returns it
	map<string, string> newMap;
	newMap["1"] = "one"; //newMap.insert(pair<int, string>(1,"one")); 
	newMap["2"] = "two";
	newMap["3"] = "three";
	newMap["4"] = "four";
	newMap["5"] = "five";
	newMap["6"] = "six";
	newMap["7"] = "seven";
	newMap["8"] = "eight";
	newMap["9"] = "nine";
	newMap["10"] = "ten";
	newMap["11"] = "eleven";
	newMap["12"] = "twelve";
	newMap["13"] = "thirteen";
	newMap["14"] = "fourteen";
	newMap["15"] = "fifteen";
	newMap["16"] = "sixteen";
	newMap["17"] = "seventeen";
	newMap["18"] = "eighteen";
	newMap["19"] = "nineteen";
	newMap["20"] = "twenty";
	newMap["30"] = "thirty";
	newMap["40"] = "forty";
	newMap["50"] = "fifty";
	newMap["60"] = "sixty";
	newMap["70"] = "seventy";
	newMap["80"] = "eighty";
	newMap["90"] = "ninety";
	newMap["100"] = "one hundred";
	newMap["200"] = "two hundred";
	newMap["300"] = "three hundred";
	newMap["400"] = "four hundred";
	newMap["500"] = "five hundred";
	newMap["600"] = "six hundred";
	newMap["700"] = "seven hundred";
	newMap["800"] = "eight hundred";
	newMap["900"] = "nine hundred";
	newMap["1000"] = "one thousand";	

	return (newMap);
}

int main() {
	map<string, string> ones = createOneToNineteenMap();
	int number = 0;

	cout << endl << "Enter a number between 1 and 1000: ";
	cin >> number;

	int validNumber = getValidNumber(number);
	cout << endl << "Number: " << validNumber << endl;

	string aNumber = to_string(validNumber);
	string result = generateWrittenNumber(ones, aNumber);	
	cout << endl << "Written Number: " << result << endl;

	int countLetters = getNumberOfLettersString(result);
	cout << endl << "Number of letter used to write the number: " << countLetters << endl;

	int totalLetters = 0;
	for (int i = 1; i < 1000; i++) {
		string aNumber = to_string(i);
		string result = generateWrittenNumber(ones, aNumber);	
		totalLetters = totalLetters + getNumberOfLettersString(result);
	}

	cout << endl << "If all the numbers from 1 to 1000 inclusive were written out in words, how many letters would be used? ";
	cout << totalLetters << " letters would be used." << endl << endl;

}
