/*
Khử đệ quy.
- Viết lại thuật toán theo kiểu đệ quy của phương pháp sắp xếp phân đoạn.
- Khử đệ quy thuật toán sắp xếp phân đoạn vừa viết.
- Cài đặt chương trình thực hiện:
o Khởi tạo mảng a gồm tối thiểu 3000 số nguyên, các số được khởi tạo ngẫu 
nhiên.
o Áp dụng thuật toán sắp xếp phân đoạn vừa được khử đệ quy để sắp xếp, 
theo dõi thời gian chạy thuật toán.
*/


#include<bits/stdc++.h>
using namespace std;
#define max 3000

// de quy cho phuong phap phan doan - quicksort
void quicksort(int a[], int l, int r){
    if(l>=r) return;

    int pivot = a[l + (r-l)/2];
    int i=l, j=r;

    while(i<=j){
        while(a[i] < pivot){
            i++;
        }

        while(a[j] > pivot){
            j--;
        }

        if(i<=j){
            int tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
            i++; j--;
        }

        if(l<j) quicksort(a, l, j);
        if(r>i) quicksort(a, i, r);
    }
}

void printArr(int a[], int size){
    for(int i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void khuDeQuy(int a[], int l, int r){
    stack<pair<int, int>> stack;
    stack.push({l, r});

    while(!stack.empty()){
        int left = stack.top().first;
        int right = stack.top().second;
        stack.pop();


        int pivot = a[left + (right-left)/2];
        int i=left, j=right;

        while(i<=j){
            while(a[i] < pivot) i++;
            while(a[j] > pivot) j--;

            if(i<=j){
                swap(a[i], a[j]);
                i++; 
                j--;
            }
        }

        if(left < j) stack.push({left, j});
        if(i<right) stack.push({i, right});
    }
}

int main(){
    int a[max];
    srand(time(nullptr));

    for(int i=0; i<max; i++){
        a[i] = rand();
    }
    // quicksort(a, 0, max-1);
    khuDeQuy(a, 0, max-1);
    printArr(a, max);
}