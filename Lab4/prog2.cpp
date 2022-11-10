#include <iostream>

using namespace std;

int main() {

	int arrayOfNumbers[5] = {1,2,3,4,5};

	for(int i =-50; i<=15; i++){

		if(i==0) {
			cout << "----- BEGIN ARRAY -----" << endl;
		}

		if(i==5) {
			cout << "----- END ARRAY -----" << endl;
		}

		cout << arrayOfNumbers[i] << endl;
	}

	return 0;
}
