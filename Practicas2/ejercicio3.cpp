#include <iostream>
using namespace std;
int main (){
  int a, b, suma = 0;
  cout << "Introduce a";
  cin >> a;
  cout << "Introduce b";
  cin >> b;
  for (int i = a; i <= b; i++) {
   suma = suma + i;
 }
 cout << suma << endl;
return 0;
}
