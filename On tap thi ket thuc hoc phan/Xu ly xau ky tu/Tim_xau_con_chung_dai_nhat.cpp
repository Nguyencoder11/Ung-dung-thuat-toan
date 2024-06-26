#include<bits/stdc++.h>
using namespace std;

/*
- Phuong phap: Su dung thuat toan quy hoach dong
+ L(i,j) la do dai xau con chung dai nhat cua xau Ai va xau Bj 
+ L(0,j) = L(i,0) = 0 // mot trong 2 xau la rong
+ L(i,j) = L(i-1, j-1) + 1 neu A[i] = B[j]
+ L(i,j) = max(L[i-1][j], L[i][j-1]) neu A[i] != B[j]
*/

void xauConChungDaiNhat(string A, string B) {
    for(int i = 0; i <= A.length(); i++) L[i][0] = 0;
    for(int j = 0; j <= B.length(); j++) L[0][j] = 0;

    for(int i = 1; i <= A.length(); i++) {
        for(int j = 1; j <= B.length(); j++) {
            if(A[i-1] == B[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
            }else{
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }

    return L[A.length()][b.length()];
}

// truy vet tim xau con chung dai nhat
void xau_con(string A, string B) {
    int i = A.length(), j = B.length(), k = 0;

    while(L[i][j] != 0) {
        if(A[i-1] == B[j-1]) {
            xc[k++] = A[i-1];
            i--; j--;
        }else{
            if(L[i-1][j-1] > L[i][j-1]) i--;
            else j--;
        }
    }
    xc[k] = '\0';
    strrev(xc);
}

int main() {

}