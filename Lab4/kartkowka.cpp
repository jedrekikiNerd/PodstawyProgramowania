#include <iostream>
#include <climits>

using namespace std;

int main(){

	int liczba; int ilosc = 0; int najw = 0; int najm = INT_MAX; int suma = 0;

	for(int i=1; i<=30; i++) {

		if(i%2) {

			cout << "Podaj liczbę dodatnią ";
		}
		else {

			cout << "Podaj liczbę ujemną ";
		}

		cin >> liczba;

		if(liczba%3 == 0) {
			cout << "Liczba podzielna przez 3" << endl;
			ilosc++;
			suma += liczba;
			if(najw < liczba) {
				najw = liczba;
			}
			if(najm > liczba){
				najm = liczba;
			}
		}
	}

	cout << "Ilosc: " << ilosc << endl << "Suma: " << suma << endl << "Największa: " << najw << endl << "Najmniejsza: " << najm << endl;
	return 0;
}
