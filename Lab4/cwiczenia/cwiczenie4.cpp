#include <iostream>
#include <climits>

using namespace std;

float srednia(int tablica[], float size){

	float suma = 0;

	for(int i=0; i<size; i++) {

		suma += tablica[i];
	}

	float wynik = suma / size;
	return wynik;
}

int najwieksza(int tablica[], int size) {

	int naj = INT_MIN;

	for(int i=0; i<size; i++){

		if(tablica[i] > naj) {
			naj = tablica[i];
		}
	}

	return naj;
}

int najmniejsza(int tablica[], int size) {

	int najm = INT_MAX;

	for(int i=0; i<size; i++) {

		if(tablica[i] < najm) {
			najm = tablica[i];
		}
	}

	return najm;
}

int main(){
	int n = 10;
	int tab[n];

	for(int i=0; i<10; i++){

		cin >> tab[i];
	}

	cout << "Średnia: " << srednia(tab, n) << endl;
	cout << "Największa zmienna w tablicy: " << najwieksza(tab, n) << endl;
	cout << "Najmniejsza zmienna w tablicy: " << najmniejsza(tab, n) << endl;

	return 0;
}
