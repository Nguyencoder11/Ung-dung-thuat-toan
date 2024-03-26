#include<bits/stdc++.h>
using namespace std;

long UCLN(long a, long b){
    if(b == 0) return a;
    if(a == 0) return b;
    while(b > 0) {
        long r = a % b;
        a = b; b = r;
    }
    return a;
}

int main(){
    long a, b;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    if(a<0 || b<0){
        cout << "Nhap lai a, b: "; cin >> a >> b;
    }

    cout << "UCLN(" << a << "," << b << ") = " << UCLN(a, b);
}