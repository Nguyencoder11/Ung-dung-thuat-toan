#include<bits/stdc++.h>
using namespace std;
#define n 8


// tao ban co
int board[n][n] = {0};

// in ban co
void printBoard(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << "\t";
        }
        cout << "\n\n\n";
    }
}

// kiem tra nuoc di tiep theo co ton tai tren ban co hay khong
bool isValidMove(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == 0);
}

// su dung backtracking de tim duong di cua quan ma
bool solveKTUtil(int u, int v, int movei, int x[], int y[]){
    int next_x, next_y;
    if(movei == n*n) return true;

    // Thu tat ca cac buoc di cua quan ma
    for(int i=0; i<8; i++){
        next_x = u + x[i];
        next_y = v + y[i];

        if(isValidMove(next_x, next_y)){
            board[next_x][next_y] = movei;
            if(solveKTUtil(next_x, next_y, movei+1, x, y) == true){
                return true;
            }else{
                board[next_x][next_y] = 0;
            }
        }
    }
    return false;
}

int main(){
    // tao vi tri dau tien cua quan ma
    int u=0, v=0;

    // tao 2 mang luu tru 8 vi tri theo x va theo y ma con ma co the di qua
    int x[8] = {2, 1, -1, -2, -2, -1,  1,  2};
    int y[8] = {1, 2,  2,  1, -1, -2, -2, -1};

    board[u][v] = 1;

    if(solveKTUtil(u,v,2,x,y) == false){
        cout << "Doesn't have solutions" << endl;
    }else{
        printBoard();
    }
}