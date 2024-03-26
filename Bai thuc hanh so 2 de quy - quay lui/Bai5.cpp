#include<bits/stdc++.h>
using namespace std;

void chuyen(int n, char a, char b, char c){
    if(n == 1) {
        cout << "Chuyen " << n << " dia tu cot " << a << " sang cot " << c << endl;
    } else {
        chuyen(n-1, a, c, b);
        chuyen(1, a, b, c);
        chuyen(n-1, b, a, c);
    }
}

int main(){
    int n;
    char a = 'A', b = 'B', c = 'C';
    cout << "So dia: "; cin >> n;
    chuyen(n, a, b, c); 
}