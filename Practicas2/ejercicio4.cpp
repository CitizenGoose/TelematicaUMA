#include <iostream>
using namespace std;
int main (){
  int a, b, suma = 0;
  int d1, d2;
  cout << "Introduce a";
  cin >> a;

  cout << "Introduce b";
  cin >> b;

  cout << "Introduce divisor 1";
  cin >> d1;
  cout << "Introduce divisor 2";
  cin >> d2;

  for (int i = a; i <= b; i++) {
   if ((i % d1 == 0) && (i % d2 == 0)){
    suma = suma + i;
}

 }
 cout << suma << endl;
return 0;
}
