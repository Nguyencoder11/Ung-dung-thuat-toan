#include<bits/stdc++.h>
using namespace std;

float power(float a, int n) {
    if(n == 1) return a;
    if(n % 2 == 0) return power(a, n/2)*power(a, n/2);
    else return power(a, n/2)*power(a, n/2)*a;
}

int main() {
    float a;
    int n;
    cout << "Nhap so thuc a: "; cin>>a;
    cout << "Nhap so nguyen n: "; cin>>n;

    cout << "Ket qua: " << power(a, n);
}