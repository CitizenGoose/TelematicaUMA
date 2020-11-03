#include <iostream>
using namespace std;
int main() {
 float n;
 int entera;
 float decimal;

 cout << "Introduce un número" << endl;
 cin >> n;

 entera = int(n);

 decimal = n - float (entera);
 
 cout << "decimal = " << decimal << endl << "entera = " << entera << endl;
 
return 0;
}
