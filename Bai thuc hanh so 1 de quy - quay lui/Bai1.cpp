#include <bits/stdc++.h>
using namespace std;
#define size 100

/*
 * Cai dat chuong trinh sinh cac chuoi nhi phan do dai n.
 * ap dung phuong phap sinh
 */

// Sinh cau hinh moi tu cau hinh ban dau
void next_config(int x[], int n, int i){
    x[i] = 1;
    i++;
    while(i<=n){ // Dat x[i+1],...,x[n] = 0;
        x[i] = 0;
        i++;
    }
}

// Hien thi cau hinh
void view_config(int x[], int n){
    for(int i=1; i<=n; i++){
        cout<<x[i];
    }
    cout<<endl;
}


// Liet ke cac cau hinh
void list_config(int n){
    int i;
    int x[n+1] = {0}; // Gan cau hinh dau tien bang {00...0}
    do{
        view_config(x,n);
        i = n;
        while(i>0 && x[i] == 1){
            i--;
        }
        if(i>0){ // Chua phai cau hinh cuoi
            next_config(x, n, i);
        }
    }while(i>0);
}


int main(){
    int n;
    int x[size];
    cout<<"Do dai day nhi phan: ";
    cin >> n;
    list_config(n);
}