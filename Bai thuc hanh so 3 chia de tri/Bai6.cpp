#include<bits/stdc++.h>
using namespace std;

int find_min_even(int a[], int l, int r) {
    if(l == r) {
        if(a[l] % 2 == 0) {
            return a[l];
        } else {
            return INT_MAX;
        }
    }
    int m = l + (r - l) / 2;
    int leftMin = find_min_even(a, l, m);
    int rightMin = find_min_even(a, m+1, r);
    if(leftMin % 2 == 0) {
        return (leftMin < rightMin) ? leftMin : rightMin;
    } else {
        return rightMin;
    }
}

int main() {
    int a[20] = {1, 4, 6, 2, 4, 3, 8, 6, 7, 12, 9, 15, 13, 6, 17, -5, -6, 2, 4, 5};

    int minEven = find_min_even(a, 0, 19);
    if(minEven != INT_MAX) {
        cout << "So chan nho nhat trong danh sach: " << minEven;
    } else {
        cout << "Khong co so chan trong danh sach";
    }
}