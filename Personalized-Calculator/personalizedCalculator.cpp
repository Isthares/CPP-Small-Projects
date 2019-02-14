//  Esther Heralta Espinosa
//  02/11/19
//
//  Created by Esther Heralta Espinosa on 11/02/2019.
//  Copyright © 2019 Esther Heralta Espinosa. All rights reserved.

#include <string>
#include <cmath> //pow(base, exponent), sqrt(number), fmod(num1, num2)
#include <iostream>
using namespace std;

// ------ basic arithmetic functions ------
float addition (float a, float b) {
    return (a + b);
}

float subtraction (float a, float b) {
    return (a - b);
}

float multiplication (float a, float b) {
    return (a * b);
}

float division (float a, float b) {
    return ((float)a / (float)b);
}

//it returns modulus of two float
float mod (float a, float b) {
    return (fmod(a, b));
}

//it computes a base number raised to the power of exponent number
float exponential (float base, float exponent) {
    return (pow(base, exponent));
}

//it returns the square root of a number
float squareRoot (float number) {
    return (sqrt(number));
}

// ---------------------------------------

//display menu
void displayMenu () {
    cout << "    ------ CALCULATOR MENU ------" << endl << endl;
    cout << "    · Addition  ......... Press a" << endl << endl;
    cout << "    · Subtraction  ...... Press s" << endl << endl;
    cout << "    · Multiplication .... Press m" << endl << endl;
    cout << "    · Division .......... Press d" << endl << endl;
    cout << "    · Reminder .......... Press r" << endl << endl;
    cout << "    · Exponential ....... Press e" << endl << endl;
    cout << "    · Square Root ....... Press q" << endl << endl;
    cout << "    · Exit .............. Press *" << endl << endl;
    cout << "    -----------------------------" << endl;
}

//the user choose an option of the menu
char chooseOption () {
    char option;
    displayMenu(); //display menu
    cout << endl << "    Choose an option: ";
    cin >> option;
    return (option);
}

//get number
float getNumber (const string& number) {
    float num;
    cout << "        * Enter " + number + " number: ";
    cin >> num;
    return (num);
}

//verify the user the otion chosen
void optionMessage (const string& userName, const string& operation) {
    cout << endl << "        " << userName << " you have chosen " + operation + " operation" << endl;
}

//print the result
void resultMessage (float num1, float num2, const string& operation, float result) {
    if (operation.compare("The square root of ") == 0) {
        cout << "        >>>> " << operation << num1 << " is ";
    } else {
        cout << "        >>>> " << num1 << operation << num2 << " is ";
    }
    printf("%.2f \n\n\n", result);   
}

//perform the operation chosen by the user
void performOperation (const string& operation, const string& op, const string& userName) {
    float x1 = 0; //first number
    float x2 = 0; //second number
    float finalValue = 0.0; //final value

    optionMessage(userName, operation);
    x1 = getNumber("first");
    if (operation.compare("addition") == 0) {
        x2 = getNumber("second");
        finalValue = addition (x1, x2);
    } else if (operation.compare("subtraction") == 0) {
        x2 = getNumber("second");
        finalValue = subtraction (x1, x2);
    } else if (operation.compare("multiplication") == 0) {
        x2 = getNumber("second");
        finalValue = multiplication (x1, x2);
    } else if (operation.compare("division") == 0) {
        x2 = getNumber("second");
        finalValue = division (x1, x2);
    } else if (operation.compare("exponential") == 0) {
        x2 = getNumber("second");
        finalValue = exponential(x1, x2);
    } else if (operation.compare("square root") == 0) {
        x2 = 0;
        finalValue = squareRoot(x1);
    }
    else {
        x2 = getNumber("second");
        finalValue = mod (x1, x2);
    }    

    resultMessage(x1, x2, op, finalValue);
}


int main() {
    
    string fullName; //user's name
    char letter; //it represents the operation chosen by the user
    
    //ask the user to enter his/her name
    cout << endl << "Please enter your name: "; 
    getline(cin, fullName);
    
    //welcome the user
    cout << endl << "    Welcome " << fullName << "!" << endl << endl;
    
    letter = chooseOption(); //asking the user to choose an option

    while (letter != '*'){ //while the option is not exit   

        switch (letter) {
            case 'a': performOperation("addition", " plus ", fullName);
                      break;
            case 's': performOperation("subtraction", " minus ", fullName);
                      break;
            case 'm': performOperation("multiplication", " times ", fullName);
                      break;
            case 'd': performOperation("division", " divided by ", fullName);
                      break;
            case 'r': performOperation("mod", " mod ", fullName);
                        break;
            case 'e': performOperation("exponential", " raised to the power of ", fullName);
                      break;
            case 'q': performOperation("square root", "The square root of ", fullName);
                      break;
            default:  cout << endl << fullName << " you have chosen an invalid entry." << endl << endl;
                      break;
        }

        letter = chooseOption(); //asking the user to choose an option
    }

    //say goodbye
    cout << endl << "    Goodbye " << fullName << "!!" << endl << endl;
    return 0;
}
