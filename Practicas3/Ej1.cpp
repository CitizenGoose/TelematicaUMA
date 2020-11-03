#include <iostream>

using namespace std;

int main(){
	int i, n;
	bool isPrime = true;
	cout << "int; ";

	cin >> n;
	if(n == 0){
		isPrime = false;
	}
	else{
		for(i = 2; i <= n/2; i++){
			if(n%i == 0){
				isPrime;
				break;
			}
		}
	}
	if(isPrime){
		cout << "prima";
	}
	else{
		cout << "no es prima";
	}
	return 0;
}
