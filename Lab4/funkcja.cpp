#include <iostream>

using namespace std;

//Funkcja wypelniajaca tablice liczbami podanymi przez użytkownika
//Przekazywane argumenty - 1. tablica, 2. rozmiar tablicy
int* wypelnij_tablica(int arr[], int size) {

	for(int i=0; i<size; i++) {
		cout << "Podaj kolejną liczbę w tablicy: ";
		cin >> arr[i];
	}

	return arr;
}

//Funkcja drukujaca tablice
//Przekazywane argumenty - 1. tablica, 2. rozmiar tablicy
void drukuj_tablice(int arr[], int size) {

	int i = 0;
	cout << "[";
	for(i=0; i<size-1; i++) {

		cout << arr[i] << ", ";
	}
	cout << arr[i] << "]\n";
}

int main() {

	int size;
	int* ptr;
	cout << "Podaj rozmiar tablicy" << endl;
	cin >> size;
	int arr[size];
	ptr = wypelnij_tablica(arr, size);
	drukuj_tablice(ptr, size);


	return 0;
}
