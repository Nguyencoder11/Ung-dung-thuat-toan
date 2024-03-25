/*
 * Cai dat chuong trinh sinh cac chuoi nhi phan do dai n.
 * ap dung phuong phap quay lui
 */

#include<bits/stdc++.h>
using namespace std;

void show(int x[], int n){
    for(int i=1; i<=n; i++){
        cout << x[i];
    }
    cout << endl;
}

void Try(int x[], int k, int n){
    for(int i=0; i<=1; i++){
        x[k] = i;
        if(k == n){
            show(x, n);
        }else{
            Try(x, k+1, n);
        }
    }
}

int main(){
    int n;
    cin >> n;
    int k=1;
    int x[100];
    Try(x,k,n);
}