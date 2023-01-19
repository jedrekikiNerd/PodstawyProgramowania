#include <iostream>
#include "variableManagement.h"
#include "display.h"

using namespace std;


//Czyszczenie terminala
void clear_terminal() {
    system("clear");
}


//Wypisz podany wiersz z każdej kolumn w równych odstępach
void print_row(int row, int longest_each_column[], bool zero_row = false) {

    if (!zero_row)
        cout << row+1 << ".  ";
    else
        cout << "    ";
    
    for (int column=0; column<COLUMNS_QUANTITY; column++) {

        int required_spaces = 0;

        if (!zero_row) {
            cout << Table[column][row];
            required_spaces = longest_each_column[column] - Table[column][row].size();
        }
        else {
            cout << Labels[column];
            required_spaces = longest_each_column[column] - Labels[column].size();
        }

        for (int spaces_quantity = 0; spaces_quantity <= required_spaces; spaces_quantity++)
            cout << " ";

        cout << "   ";

    }
    cout << endl;
}


//Znajdź najdłuizszy string w kolumnie
void find_longest(int longest_each_column[]) {

    for(int label=0; label<COLUMNS_QUANTITY; label++)
        longest_each_column[label] = Labels[label].size();

    for (int column=0; column<COLUMNS_QUANTITY; column++) {

        for (int row=0; row<number_elements; row++) {

            if (Table[column][row].size() >= longest_each_column[column])
                longest_each_column[column] = Table[column][row].size();
        }
    }
}

//Wyświetl tabelę
void display_table() {
    cout << endl;
    clear_terminal();

    int longest_each_column[COLUMNS_QUANTITY] = {0};
    find_longest(longest_each_column);
    print_row(0, longest_each_column, true);

    for (int row = 0; row<number_elements; row++) {

        print_row(row, longest_each_column);
    }
}

//Wyszukaj i wyświetl pasujące wartości
void display_find_values(int column, string value) {
    column -= 1;
    cout << "Wyniki wyszukiwania" << endl;
    clear_terminal();

    int longest_each_column[COLUMNS_QUANTITY] = {0};
    find_longest(longest_each_column);
    print_row(0, longest_each_column, true);

    for (int row = 0; row<number_elements; row++) {
        if (Table[column][row] == value)
            print_row(row, longest_each_column);
    }
}