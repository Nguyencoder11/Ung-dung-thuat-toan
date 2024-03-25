#include<bits/stdc++.h>
using namespace std;

/*
 * Cai dat chuong trinh sinh cac tap con k phan tu tu tap S = {1, 2, ..., n}.
 *
 */

// Sinh cau hinh moi
void next_config(int x[], int k, int i){
    x[i] += 1;
    i++;
    while(i<=k){ // x[i+1],....x[k] = can duoi
        x[i] = x[i-1] + 1;
        i++;
    }
}

// hien thi cau hinh
void view_config(int x[], int k){
    
}

int main(){

}