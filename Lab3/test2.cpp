#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

	if(argc != 1) {

		if(string(argv[1]) == "-h") {

			cout << "Ekran pomocy" << endl;
		
		}

		for(int i=1; i<argc; i++) {
			cout << string(argv[i]) << endl;
		}

		cout << "Ilość argumentów: " << argc <<endl;

	}

	else {
		cout << "Brak argumentów" << endl;
	}
}
