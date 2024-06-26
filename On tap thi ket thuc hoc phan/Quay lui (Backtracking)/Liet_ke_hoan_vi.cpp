#include<bits/stdc++.h>
#define size 100
using namespace std;

void list_config(int x[], int n) {
    for(int i=1; i<=n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

void Try(int k, int x[], int n, int *dd) {
    for(int i = 1; i <= n; i++) {   // Duyet cac phan thuoc tap S = {1, 2, ..., n}
        if(dd[i] == 0) {    // chap nhan duoc la chua duoc chon truoc do
            x[k] = i;
            if(k == n) {    // neu tim duoc phan tu cuoi thi in cau hinh
                list_config(x, n);
            } else {
                dd[i] = 1;  // danh dau viec chon i cho x[k]
                Try(k+1, x, n, dd); 
                dd[i] = 0;  // huy ghi nhan viec chon i cho x[k]
            }
        }
    }
}

int main(){
    int x[size], n, k = 1;
    int dd[size];
    
    cout << "So phan tu cua tap S: "; cin >> n;

    for(int i = 1; i <= n; i++) {
        dd[i] = 0;
    }
    Try(k, x, n, dd);
}