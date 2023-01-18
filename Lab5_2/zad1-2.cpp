#include <iostream>
#include <fstream>

using namespace std;

string *liczby;
int i = 0;
string zapisz() {

    fstream plik;
    plik.open ("plik2.txt");

    for(int j=i-1; j>=0; j--)
        plik << liczby[j] << "\n";
    
    plik.close();
    return "Plik zapisano pomyślnie!\n";
}


string wczytaj() {
    liczby = new string [i+1];
    fstream plik;
    plik.open("plik1.txt");

    if (!plik.good())
        return "Pliku nie udało się wczytać!\n";

    while (!plik.eof()) {
        plik >> liczby[i];
        string *tmp;
        tmp = new string [i+2];

        copy(liczby, liczby + i+1, tmp);
        
        delete[] liczby;
        liczby = tmp;
        
        i++;
    }

    plik.close();
    return "Plik wczytano pomyślnie!\n";
}


int main() {

    cout << wczytaj();
    cout << zapisz();

    return 0;
}

