#include <iostream>
using namespace std;
int main (){
int n, n2 = 0;
float m;

 cout << "introduce el número de tornillos";
 cin >> n;
 for (int i = 0; i < n; i++){
 cout << "introduce las medidas de los tornillos";
 cin >> m;
 }
  if ((m >= 3.5) && (m <= 4.5)){
  n2++;}
  cout << n2 << endl;
return 0;
}

