#include<bits/stdc++.h>
using namespace std;

void printArr(float a[]) {
    for(int i = 0; i < 15; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

float findMax(float a[], int l, int r) {
    if(l == r) return a[l];
    int m = l + (r - l) / 2;
    int leftMax = findMax(a, l, m);
    int rightMax = findMax(a, m+1, r);

    return (leftMax > rightMax) ? leftMax : rightMax;
}

int main(){
    float a[15];
    srand(time(0));
    // khoi tao cac phan tu ngau nhien cho mang
    for(int i = 0; i < 15; i++) {
        a[i] = rand() % 101;
    }
    cout << "Mang khoi tao ban dau: ";
    printArr(a);

    cout << "Gia tri lon nhat mang: " << findMax(a, 0, 14) << endl;    
}