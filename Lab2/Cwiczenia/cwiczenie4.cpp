#include <iostream>

int main(){
	int a = 2;
	int wynik = 0;
	for(int i=0; i<10; i++){
		wynik += a;
		a = a*a;
	}
	std::cout << wynik;
}
