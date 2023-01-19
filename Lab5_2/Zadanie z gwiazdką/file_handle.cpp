#include <iostream>
#include <fstream>
#include "variableManagement.h"
#include "file_handle.h"

using namespace std;

int readfile(string path) {
    fstream file;
    string line;
    file.open(path);

    if (!file.good())
        return 1;

    while (!file.eof()) {

        for (int column = 0; column < COLUMNS_QUANTITY; column++)
            file >> NewRecord[column];
        
        add_record();
    }

    file.close();
    return 0;
}

int writefile(string path){
    ofstream file;
    string line;
    file.open(path);

    if (!file.good())
        return 1;


    for ( int row=0; row < number_elements; row++ ) {

        line = "";

        for ( int column = 0; column < COLUMNS_QUANTITY; column++ ) {

            line += Table[column][row];
            if (column != COLUMNS_QUANTITY-1)
                line += " ";
        }

        if (row != number_elements-1)
            line += "\n";

        file << line;

    }
    return 0;
}