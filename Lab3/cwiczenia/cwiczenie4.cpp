#include <iostream>

using namespace std;

int main() {

	float bigNumber = 100;
	while (bigNumber > 0.00004) {
		cout << bigNumber << endl;
		bigNumber /= 2;
	}

	return 0;
}
