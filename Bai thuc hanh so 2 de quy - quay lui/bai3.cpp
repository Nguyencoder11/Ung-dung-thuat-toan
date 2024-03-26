#include<bits/stdc++.h>
using namespace std;

long fibonacci(long n){
    if(n == 1 || n == 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    long n;
    cout << "n = "; cin >> n;
    if(n < 0){
        cout << "Nhap lai n: "; cin >> n;
    }

    cout << "So fibonacci thu " << n << " la: " << fibonacci(n);
}