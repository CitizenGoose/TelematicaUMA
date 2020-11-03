#include <iostream>
using namespace std;
int main () {
  char letra;
  int variable = 1;
  cout << "introduce una palabra acabada en punto";
  cin >> letra;

  while (letra != '.') {
  letra = variable + letra;

  cout << letra <<endl;
  cin >> letra;
  variable++;

}
return 0;
}
