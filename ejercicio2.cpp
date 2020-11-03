#include <iostream>
using namespace std;
int main () {
	unsigned n;
	unsigned r;
	unsigned i;
	cout << "Introduce un número del 1 al 10";
	cin >> n;
//Ponemos la condición de que si es distinto a 1 o 10 salte error
	if ((n >= 10) || (n <= 1)) {
	cout << "error";
	return 0;
	
}
	for (i = 1; i <= 10; i++) {
	r = n * i;
	cout << n << "x" << i << "=" << r << endl;
	
	 }

return 0;
}
