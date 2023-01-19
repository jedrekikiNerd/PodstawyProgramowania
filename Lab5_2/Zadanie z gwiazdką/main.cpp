#include <iostream>
#include "file_handle.h"
#include "variableManagement.h"
#include "display.h"
#include <unistd.h>

using namespace std;

//Inicjalizacja zmiennych i wczytanie pliku
int init() {
    init_variables();
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

//Obsługa komend
int command_handle(string command) {

    if (command == "add") {
        for (int column=0; column<COLUMNS_QUANTITY; column++) {
            cout << "Podaj " << Labels[column] << ": ";
            cin >> NewRecord[column];
        }
        add_record();
    }

    else if (command == "exit") {
        string confirmation;
        cout << "Upewnij się, że zapisałeś swoje zmiany!\nCzy na pewno chcesz zamknąć program Tak/Nie: ";
        cin >> confirmation;

        if (confirmation == "Tak")
            return 2;
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

    else if (command == "help") {
        clear_terminal();
        cout << "Dostępne komendy:\n";
        cout << "help - wyświetla listę poleceń i ich funkcje\n";
        cout << "add - dodaje nowy wiersz do tabeli\n";
        cout << "delete - usuwa wybrany wiersz z tabeli\n";
        cout << "find - wyszkuje konkretną wartość w danej kolumnie\n";
        cout << "open - otwiera edycję nowej tabeli z wybranego pliku\n";
        cout << "save - zapisuje tabelę do podanego pliku\n";
        cout << "exit - wyjście z programu\n";
        cout << "***Wpisz quit, aby wyjść z sekcji pomocy***\n";
        string quiter;
        cin >> quiter;
        
    }

    else if (command == "find") {
        string search_value;
        int search_column;

        cout << "Podaj numer kolumny w jakiej chcesz wyszukać wartość: ";
        cin >> search_column;

        if (search_column < 1 || search_column > COLUMNS_QUANTITY) {
            cout << "ERROR: Nie ma kolumny o takim numerze!\n";
            return 1;
        }

        cout << "Podaj szukaną wartość: ";
        cin >> search_value;

        display_find_values(search_column, search_value);
        return 3;
        
    }

    else if (command == "open") {
        string file_name;
        cout << "UWAGA! Otwierając nowy plik nie zapisując poprzedniego utracisz wszystkie zmiany!\n";
        cout << "Podaj nazwę pliku z listą obecności z jakiego chcesz korzystać: ";
        cin >> file_name;
        
        int tmp = number_elements;
        number_elements = 0;

        if(readfile(file_name)) {
            cout << "ERROR: Nie udało się wczytać pliku!\n";
            number_elements = tmp;
            return 1;
        }
        
    }

    else {
        cout << "Wpisana komenda nie istnieje!\n";
        return 1;
    }

    return 0;

}

//Główna pętla
int main(){
    bool search_result_lock = false;
    if (init()) {
        cout << "Napotkano problem! Nie można kontynuować!\n";
        return 1;
    }
    else
        cout << "Inicjalizacja przebiegła pomyślnie!\n";
    
    sleep(2);


    while (true) {
        if (!search_result_lock)
            display_table();


        string cmd = "";
        cout << "\n\n\nWpisz komendę: ";
        cin >> cmd;
        search_result_lock = false;


        int cmd_code = command_handle(cmd);

        //Sprawdź kod zwrócony przez funkcje od obsługi komend
        if (cmd_code == 1) {
            cout << "Napotkano problem! Zaraz nastąpi powrót do edycji danych!\n";
            sleep(5);
        }

        else if (cmd_code == 2) {
            clear_terminal();
            cout << "Do zobaczenia!\nZaraz nastąpi wyłączenie!\n";
            delete_table();
            sleep(3);
            return 0;
        }

        else if (cmd_code == 3) {
            search_result_lock = true;
        }
    }
}