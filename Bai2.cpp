#include <bits/stdc++.h>
using namespace std;

/*
 * Cai dat chuong trinh sinh cac chuoi ky tu do dai chi chua ky tu 'a' va 'b'.
 * ap dung phuong phap sinh
 */

// Sinh cau hinh moi tu cau hinh ban dau
void next_config(char x[], int n, int i){
    x[i] = 'b';
    i++;
    while(i<=n){ // Dat x[i+1],...,x[n] = 'a';
        x[i] = 'a';
        i++;
    }
}

// Hien thi cau hinh
void view_config(char x[], int n){
    for(int i=1; i<=n; i++){
        cout<<(char)x[i];
    }
    cout<<endl;
}


// Liet ke cac cau hinh
void list_config(int n){
    int i;
    char x[n+1] = {'a'}; // Gan cau hinh dau tien bang {aa...a}
    do{
        view_config(x,n);
        i = n;
        while(i>0 && x[i] == 'b'){
            i--;
        }
        if(i>0){ // Chua phai cau hinh cuoi
            next_config(x, n, i);
        }
    }while(i>0);
}

int main(){
    int n;
    char x[100];
    cout << "Nhap do dai chuoi ky tu: ";
    cin >> n;
    list_config(n);
    return 0;
}