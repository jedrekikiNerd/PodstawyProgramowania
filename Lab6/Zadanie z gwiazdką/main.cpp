#include <iostream>
#include "file_handle.h"
#include "variableManagement.h"
#include "display.h"
#include <unistd.h>

using namespace std;

int init() {
    init_variables();
    new_table();
    string file_name = "";

    clear_terminal();

    cout << "Witaj w programie do sprawdzania obecności!\n";
    cout << "Podaj nazwę pliku z listą obecności z jakiego chcesz korzystać: ";
    cin >> file_name;

    if(readfile(file_name)) {
        cout << "ERROR: Nie udało się wczytać pliku!\n";
        return 1;
    }

    return 0;
}

int command_handle(string command) {

    if (command == "add") {
        for (int column=0; column<COLUMNS_QUANTITY; column++) {
            cout << "Podaj dane: ";
            cin >> NewRecord[column];
        }
        add_record();
    }

    else if (command == "exit") {
        string confirmation;
        cout << "Upewnij się, że zapisałeś swoje zmiany!\nCzy na pewno chcesz zamknąć program Tak/Nie: ";
        cin >> confirmation;

        if (confirmation == "Tak") {
            cout << "Zamykanie!";
            free_all();
            sleep(3);
            return 2;
        }
    }
    
    else if (command == "save") {
        string file_path;
        cout << "Podaj nazwę pliku do którego chcesz zapisać dane: ";
        cin >> file_path;
        if (writefile(file_path)) {
            cout << "ERROR: Nie udało się otworzyć pliku!";
            return 1;
        }
    }

    else if (command == "delete") {
        int delete_id = 0;
        cout << "Podaj numer wpisu, który chcesz usunąć: ";
        cin >> delete_id;

        if (delete_id < 1 || delete_id > number_elements) {
            cout << "ERROR: Podany przez ciebie numer wiersza nie istnieje!\n";
            return 1;
        }

        delete_record(delete_id);
    }


    return 0;

}

int main(){
    if (init()) {
        cout << "Napotkano problem! Nie można kontynuować!\n";
        return 1;
    }
    else
        cout << "Inicjalizacja przebiegła pomyślnie!\n";
    
    sleep(2);

    while (true) {
        display_table();

        string cmd = "";
        cout << "\n\n\nWpisz komendę: ";
        cin >> cmd;

        int cmd_code = command_handle(cmd);

        if (cmd_code == 1) {
            cout << "Napotkano problem! Zaraz nastąpi powrót do edycji danych!\n";
            sleep(5);
        }
        else if (cmd_code == 2) {
            cout << "Do zobaczenia!\nZaraz nastąpi wyłączenie!\n";
            sleep(3);
            return 0;
        }
    }
}