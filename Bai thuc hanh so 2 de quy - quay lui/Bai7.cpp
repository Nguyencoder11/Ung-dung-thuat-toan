#include<bits/stdc++.h>
#define size 100
using namespace std;

void list_config(int x[], int n){
    for(int i=1; i<=n; i++){
        cout << x[i];
    }
    cout << endl;
}

void Try(int k, int x[], int n){
    for(int i = 0; i <= 1; i++){
        x[k] = i;
        if(k == n){
            list_config(x, n);
        }else{
            Try(k+1, x, n);
        }
    }
}

int main(){
    int x[size], n, k=1;
    cout << "Nhap do dai chuoi nhi phan: "; cin >> n;
    Try(k, x, n);
}