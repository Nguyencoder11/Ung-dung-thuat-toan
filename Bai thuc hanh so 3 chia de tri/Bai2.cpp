#include<bits/stdc++.h>
using namespace std;

void printArr(float a[]) {
    for(int i = 0; i < 15; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merge(float a[], int l, int m, int r) {
    int n1 = m - l + 1; // so phan tu cua mang con 1
    int n2 = r - m; // so phan tu cua mang con 2

    float left[n1], right[n2];

    for(int i = 0;  i < n1; i++) {
        left[i] = a[l + i];
    }

    for(int i = 0; i < n2; i++) {
        right[i] = a[m + 1 + i];
    }

    int i=0, j=0, k = l;

    while(i<n1 && j<n2) {
        if(left[i] < right[j]) {
            a[k++] = left[i++];
        } else {
            a[k++] = right[j++];
        }
    }
    while(i<n1) {
        a[k++] = left[i++];
    }
    while(j<n2) {
        a[k++] = right[j++];
    }
}

void merge_sort(float a[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;

        // chia mang to thanh 2 mang con de sap xep
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);

        // tron e mang con da sap xep
        merge(a, l, m, r);
    }
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

    cout << "Mang sau khi sap xep: ";
    merge_sort(a, 0, 14);
    printArr(a);
}