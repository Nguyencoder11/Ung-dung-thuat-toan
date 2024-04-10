#include<bits/stdc++.h>
using namespace std;
#define n 8


// tao ban co
int board[n][n] = {0};

// in ban co
void printBoard(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }
}

// kiem tra nuoc di tiep theo co ton tai tren ban co hay khong
bool isValidMove(int *board, int n){

}

// su dung backtracking de tim duong di cua quan ma
void Try(int *board, int *x, int *y, int &u, int &v, int n){
    int next_x, next_y;


    // Thu tat ca cac buoc di cua quan ma
    for(int i=0; i<8; i++){
        next_x = u + x[i];
        next_y = v + y[i];

        
    }
}

int main(){
    // tao vi tri dau tien cua quan ma
    int u=0, v=0;

    // tao 2 mang luu tru 8 vi tri theo x va theo y ma con ma co the di qua
    int x[8] = {2, 1, -1, -2, -2, -1,  1,  2};
    int y[8] = {1, 2,  2,  1, -1, -2, -2, -1};

    board[u][v] = 1;
    printBoard();
}