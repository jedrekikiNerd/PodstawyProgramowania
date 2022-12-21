#include <iostream>

using namespace std;

int main() {

	int a = 4;
	char b = 'a';
	int *wsk_a = &a;
	char *wsk_b = &b;
	cout <<"Wskaznik na int: " <<  wsk_a << "\nWskaznik na char: " << (void*)wsk_b << "\n";
	return 0;

}
