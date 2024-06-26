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
        cout << "\n\n";
    }
}

// Kiem tra vi tri dat quan hau board[row][col] co an toan khong
bool isSafe(int row, int col){
    int i, j;

    for(i = 0; i < col; i++) {
        if(board[row][i]) return false;
    }

    for(i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j]) return false;
    }

    for(i = row, j = col; j >= 0 && i < n; i++, j--){
        if(board[i][j]) return false;
    }

    return true;
}

bool solveNQUtil(int col){
    if(col >= n) return true;

    for(int i = 0; i < n; i++){
        if(isSafe(i, col)){
            board[i][col] = 1;
            if(solveNQUtil(col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main(){
    if(!solveNQUtil(0)){
        cout << "Solution does not exist" << endl;
    }else{
        printBoard();
    }
}