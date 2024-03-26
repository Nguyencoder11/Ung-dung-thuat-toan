#include<bits/stdc++.h>
using namespace std;

long fibonacci(long n){
    if(n == 1 || n == 2) return 1;
    long f1 = 1, f2 = 1, fn;
    while(n > 2) {
        fn = f1 + f2;
        f1 = f2; f2 = fn;
        n--;
    }
    return fn;
}

int main(){
    long n;
    cout << "n = "; cin >> n;
    if(n < 0){
        cout << "Nhap lai n: "; cin >> n;
    }

    cout << "So fibonacci thu " << n << " la: " << fibonacci(n);
}