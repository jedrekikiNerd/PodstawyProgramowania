#include "variableManagement.h"
#include <iostream>
using namespace std;

int number_elements = 0;
string **Table;
string NewRecord[COLUMNS_QUANTITY];
string Labels[COLUMNS_QUANTITY];

//Inicjacja zmiennych (główna tabela + tytuły kolumn)
void init_variables() {

    Table = new string*[COLUMNS_QUANTITY];
    new_table();

    Labels[0] = "Indeks";
    Labels[1] = "Imie";
    Labels[2] = "Nazwisko";
    Labels[3] = "Data";
    Labels[4] = "Obecność";
}


//Zwalnianie pamięci (czyszczenie kolumn przed ich powiększeniem/zmniejszeniem)
void delete_table() {

    for (int i = 0; i<COLUMNS_QUANTITY; i++)
        delete[] Table[i];
    delete[] Table;
}


//Inicjacja wierszy głównej tabeli
void new_table() {
    for (int i = 0; i < COLUMNS_QUANTITY; i++){
        Table[i] = new string [1];
        Table[i][0] = "";
    }
}


//Dodawanie rekordu do głównej tabeli
void add_record() {

    int lines = number_elements;
    string **CopyTable = new string * [COLUMNS_QUANTITY];

    for (int i = 0; i<COLUMNS_QUANTITY; i++) {

        CopyTable[i] = new string [lines+1];

        for (int j = 0; j<lines; j++)
            CopyTable[i][j] = Table[i][j];

        CopyTable[i][lines] = NewRecord[i];
    }

    delete_table();
    lines += 1;
    Table = CopyTable;

    number_elements = lines;
}

//Usuwanie rekordu z głównej tabeli
void delete_record(int row) {

    row = row - 1;

    int lines = number_elements;
    string **CopyTable = new string * [COLUMNS_QUANTITY];

    for (int i = 0; i<COLUMNS_QUANTITY; i++) {

        CopyTable[i] = new string [lines-1];

        int k = 0;
        for (int j = 0; j<lines; j++) {

            if (j != row) {
                CopyTable[i][k] = Table[i][j];
                k++;
            }
        }
    }

    delete_table();
    lines -= 1;
    Table = CopyTable;

    number_elements = lines;
}