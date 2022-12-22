#include <iostream>

using namespace std;

int main() {

	int **tab = new int *[5];

	//tworzenie kolumn
	for(int i=0; i<5; i++) {
		tab[i] = new int [4];
	}

	int *ptr = tab[0];

	for(int i=0; i<20; i++) {
		ptr[i] = i+1;
	}

	for(int i=0; i<5; i++) {
		cout << "Usuwam: " << i << "\n";
		delete[] tab[i];
	}

	delete[] tab;

	return 0;
}
