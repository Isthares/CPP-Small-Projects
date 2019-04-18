/* 
File Name: amicableNumbers.cpp
Author: Esther Heralta Espinosa
Date: 04/17/19
Description of the program: Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
			    If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbe    
			    For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. 
			    The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 2   
			    
			    Evaluate the sum of all the amicable numbers under 10000.
*/

#include <iostream>
using namespace std;

int const MAX = 10000;

int sumOfDivisorsOfAGivenNumber(int number) {
	//find all divisors of a given number and return the sum of all divisors
	int sumDivisors = 1; //any number is divisble by one
	for (int i = 2; i < number; i++) {
		if (number % i == 0) {
			sumDivisors = sumDivisors + i;
		}
	}
	return (sumDivisors);
}

void fillArrayWithSumOfDivisors (int arrayDiv[]) {
	//fill the array with the sum of divisors
	//example: index of the array 8 contains: 4 + 2 + 1 = 7 because divisors of 8 are: 4, 2, 1

	for (int index = 2; index < MAX; index++) {
		arrayDiv[index] = sumOfDivisorsOfAGivenNumber(index);
	}
}

void displayArrayContent (int arrayDiv[]) {
	//displays on the screen the content of the array
	for (int i = 2; i < MAX; i++) {
		cout << i << ": " << arrayDiv[i] << endl;
	}
}

void findAmicableNumbers(int arrayDiv[]) {
	//find amicable numbers and print them out
	cout << endl << "Pair of amicable numbers under " << MAX << ": " << endl;

	for (int index = 2; index < MAX; index++) {

		//in order to avoid segmentation fault
		if ((arrayDiv[index] < MAX) && (arrayDiv[arrayDiv[index]] < MAX)) {
			if ((index == arrayDiv[arrayDiv[index]]) && (arrayDiv[index] != index)) {
				//in order to avoid duplicate results
				if (index < arrayDiv[index]) {
					cout << "   (" << index << ", " << arrayDiv[index] << ")" << endl;
				}
			}
		}	
	}
	cout << endl;
}

int main () {
	int anArray[MAX];
	fillArrayWithSumOfDivisors(anArray);
	findAmicableNumbers(anArray);
}
