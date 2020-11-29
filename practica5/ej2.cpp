#include <iostream> 

using namespace std; 

bool esTrino(int n){
    int a, b;
    while(n != 0){
        a = n%10;
        b = (n/10)%10;

        cout << a << " - " << b << " = " << a-b << " || ";
        if(((a-b) == 3) || ((a-b) == -3)){
            n /= 10;
            if((n/10)%10 == 0){
                break;
            }
        }
        else{
            cout << "No es trino.";
            n = 1;
            break;
        }
    }

    if((n/10)%10 == 0){
        cout << "Es trino." << endl;
        return true;
    } else {
        return false;
    }

}

void tresNum(int n){
    int count = 0;
    int total = 0;

    while(count != 3){
        n++;
        if(n%2 != 0){
            count++;
            total += n;
            cout << n;
            if(count != 3){
                cout << " + ";
            }
        }
    }

    cout << " = " << total;
}

int main(){
    int n;
    cout << "n: ";
    cin >> n;

    if(esTrino(n)){
        tresNum(n);
    }
    return 0;
}
