//  Esther Heralta Espinosa
//  02/13/19
//
//  Created by Esther Heralta Espinosa on 13/02/2019.
//  Copyright © 2019 Esther Heralta Espinosa. All rights reserved.

#include "file.h"

//display exit message
void exitMessage () {
    cout <<endl << endl << "           You have exit the system." << endl << endl << endl;
}

int main() {

    Menu m;
    File f;

    m.displayMainMenu();
    char opt = m.getValidOption();

    while (opt != '4') {
        
        switch(opt) {
            case '1':   //cout << "addRecords" << endl;
                        f.addRecords(); //Add records
                        break;
            case '2':   //cout << "list Records" << endl;
                        f.listRecords(); //List records
                        break;
            case '3':   //cout << "delete records" << endl;
                        f.deleteRecords(); //Delete Records
                        break;
            default:    //cout << "exit" << endl;
                        //do nothing
                        break;
        }

        m.displayMainMenu();
        opt = m.getValidOption();
 
    }

    exitMessage();

    return (0);
}
