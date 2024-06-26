#include<bits/stdc++.h>
using namespace std;

// Su dung de quy co nho 
long C1(int n, int k) {
    if(k == 0 || k == n) return 1;
    return C1(n-1, k) + C1(n-1, k-1);
}

// Su dung khu de quy 
long C2(int n, int k) {
    long C[n+1][k+1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k && j <= i; j++) {
            if(j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }

    return C[n][k];
}

int main() {
    int n, k;
    cout << "Nhap gia tri cua n va k: ";
    cin >> n >> k;

    cout << "Ket qua voi ham C1: " << C1(n, k) << endl;
    cout << "Ket qua voi ham C2: " << C2(n, k) << endl;
}