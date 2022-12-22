#include <iostream>

using namespace std;

int main() {

	int tab2D[5][4];
	int *ptr;

	//ptr = (*int) tab2D;
	ptr = tab2D[0];

	//wpisywanie do tablicy
	for(int i=0; i<20; i++) {
		ptr[i] = i+1;
	}

	//wypisywanie z tablicy
	for(int i=0; i<20; i++) {
		cout << ptr[i] <<  " ";
		cout << ptr + i << "\n";
	}

	return 0;
}
