#include <iostream>

using namespace std;

int main() {
	//wariant while
	int i = 0;
	while (i <= 20) {
		if (i % 2 == 0) {
			cout << i << " ";
		}
		i++;
	}


	//wariant do while
	cout << endl;
	i = 0;
	do {
		if (i % 2 == 0) {
			cout << i << " ";
		}
		i++;
	}
	while (i <= 20);


	//wariant for
	cout << endl;
	for (i = 0; i <= 20; i++) {
		if (i % 2 == 0){
			cout << i << " ";
		}
	}

	return 0;
}
