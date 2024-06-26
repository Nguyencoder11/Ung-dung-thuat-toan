#include<bits/stdc++.h>
#include<stack>
#include<cmath>
using namespace std;

void chuyenDia(stack<int>& src, stack<int>& des, char s, char d){
    if(!src.empty()) {
        int top = src.top();    // dia o phia tren cung cua cot nguon
        src.pop();  // lay dia o phia tren cung 
        des.push(top);  // di chuyen de tren cung tu cot nguon sang cot dich
        cout << "Di chuyen dia " << top << " tu cot " << s << " sang cot " << d <<endl;
    }
}

void hanoi_Towel(int n){
    stack<int> A, B, C;
    char src = 'A', aux = 'B', des = 'C';

    // Xep cac dia vao cot nguon: dia lon vao truoc dia nho vao sau
    for(int i=n; i>=1; i--){
        A.push(i);
    }

    // Neu so dia la so chan, doi vi tri cot phu va cot dich
    if(n % 2 == 0){
        swap(aux, des);
    }

    // So lan di chuyen dia yeu cau cua bai toan: 2^n -1
    int total_moves = pow(2, n) - 1;

    // Di chuyen dia
    for(int i = 1; i <= total_moves; i++) {
        if (i % 3 == 1) {
            if (!A.empty() && (C.empty() || A.top() < C.top())) {
                chuyenDia(A, C, src, des);
            } else {
                chuyenDia(C, A, des, src);
            }
        } else if (i % 3 == 2) {
            if (!A.empty() && (B.empty() || A.top() < B.top())) {
                chuyenDia(A, B, src, aux);
            } else {
                chuyenDia(B, A, aux, src);
            }
        } else if (i % 3 == 0) {
            if (!B.empty() && (C.empty() || B.top() < C.top())) {
                chuyenDia(B, C, aux, des);
            } else {
                chuyenDia(C, B, des, aux);
            }
        }
    }
}

int main(){
    int n;
    cout << "So dia: "; cin >> n;
    hanoi_Towel(n); 
}