#include<bits/stdc++.h>
using namespace std;

void printArr(float a[]) {
    for(int i = 0; i < 15; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

float tinhTongDuong(float a[], int l, int r) {
    if(l == r) {
        if(a[l] > 0) return a[l];
        else return 0;
    }

    int m = l + (r - l) / 2;
    float tongTrai = tinhTongDuong(a, l, m);
    float tongPhai = tinhTongDuong(a, m+1, r);
    return tongTrai + tongPhai;
}

int main() {
    float a[20] = {1, 4, 6, 2, 4, 3, 8, 6, 7, 12, 9, 15, 13, 6, 17, -5, -6, 2, 4, 5};

    float tong = tinhTongDuong(a, 0, 19);

    cout << "Tong cac so chan trong danh sach: " << tong;
}