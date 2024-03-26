#include<bits/stdc++.h>
using namespace std;

long UCLN(long a, long b){
    if(b == 0) return a;    // Neu b = 0 thi UCLLN = a
    return UCLN(b, a%b);    // neu khong tra ve UCLN cua b va phan du a%b
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