#include <iostream>
using namespace std;
int main () {
  char letra;
  int variable = 32;
  cout << "introduce una palabra acabada en punto";
  cin >> letra;

  while (letra != '.') {
  letra = letra - variable;

  cout << letra;
  cin >> letra;

}
return 0;
}
