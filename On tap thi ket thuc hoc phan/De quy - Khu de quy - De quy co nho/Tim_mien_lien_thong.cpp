#include <bits/stdc++.h>
using namespace std;

const int m = 5, n = 6;
int O[m][n]; // Biểu diễn lưới
bool flag[m][n]; // Mảng đánh dấu ô trong lưới được xét

void loang(int i, int j) {
    flag[i][j] = true;
    if (j > 0) // Loang sang ô bên trái
        if ((O[i][j-1] == O[i][j]) && (!flag[i][j-1]))
            loang(i, j - 1);
    if (i > 0) // Loang ô bên trên
        if ((O[i-1][j] == O[i][j]) && (!flag[i-1][j]))
            loang(i - 1, j);
    if (j < n - 1) // Loang ô bên phải
        if ((O[i][j+1] == O[i][j]) && (!flag[i][j+1]))
            loang(i, j + 1);
    if (i < m - 1) // Loang ô bên dưới
        if ((O[i+1][j] == O[i][j]) && (!flag[i+1][j]))
            loang(i + 1, j);
}

int main() {
    int so_mien = 0; // Đếm số miền liên thông
    
    cout << "Nhap gia tri cua luoi (" << m << "x" << n << "):" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> O[i][j];
            flag[i][j] = false; // Khởi tạo mảng flag
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!flag[i][j]) {
                loang(i, j);
                ++so_mien;
            }
        }
    }

    cout << "So mien lien thong: " << so_mien << endl;

    return 0;
}
