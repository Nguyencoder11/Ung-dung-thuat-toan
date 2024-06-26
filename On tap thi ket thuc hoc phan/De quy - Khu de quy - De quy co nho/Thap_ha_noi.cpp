#include<bits/stdc++.h>
using namespace std;

// Thap Ha Noi su dung de quy
void HanoiTowel_Recursive(int n, char a, char b, char c) {
    if(n == 1) {
        cout << "Di chuyen " << n << " dia tu cot " << a << " sang cot " << c << endl;
    } else {
        HanoiTowel_Recursive(n-1, a, c, b);
        HanoiTowel_Recursive(1, a, b, c);
        HanoiTowel_Recursive(n-1, b, a, c);
    }
}

// Thap Ha Noi su dung khu de quy
void moveDisk(stack<int>& src, stack<int>& des, char s, char d) {
    if(!src.empty()) {
        int top = src.top();
        src.pop();
        des.push(top);
        cout << "Di chuyen dia " << top << " tu cot " << s << " sang cot " << d << endl;
    }
}

void HanoiTowel_WithoutRecursive(int n) {
    stack<int> A, B, C;
    char src = 'A', tmp = 'B', des = 'C';

    // xep cac dia vao cot nguon: dia lon nam duoi dia nho
    for(int i = n; i >= 1; i--){
        A.push(i);
    }

    // So lan di chuyen dia yeu cau 2^n-1
    int total_moves = pow(2, n) - 1;

    // neu so dia la chan thi 
    if(n % 2 == 0) {
        swap(des, tmp);
    }

    // Thuc hien cac buoc di chuyen
    for(int i = 1; i <= total_moves; i++) {
        if (i % 3 == 1) {
            if (!A.empty() && (C.empty() || A.top() < C.top())) {
                moveDisk(A, C, src, des);
            } else {
                moveDisk(C, A, des, src);
            }
        } else if (i % 3 == 2) {
            if (!A.empty() && (B.empty() || A.top() < B.top())) {
                moveDisk(A, B, src, tmp);
            } else {
                moveDisk(B, A, tmp, src);
            }
        } else if (i % 3 == 0) {
            if (!B.empty() && (C.empty() || B.top() < C.top())) {
                moveDisk(B, C, tmp, des);
            } else {
                moveDisk(C, B, des, tmp);
            }
        }
    }
}

int main() {
    int n = 3;  // so dia

    /* Khai bao cho thap Ha Noi su dung de quy */
    char a = 'A', b = 'B', c = 'C';
    cout << "======= SU DUNG DE QUY ==========" << endl;
    HanoiTowel_Recursive(n, a, b, c);

    /* Khai bao cho thap Ha Noi su dung khu de quy */
    cout << "======= SU DUNG KHU DE QUY ==========" << endl;
    HanoiTowel_WithoutRecursive(n);
}