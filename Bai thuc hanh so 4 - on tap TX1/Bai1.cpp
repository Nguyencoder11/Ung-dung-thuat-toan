/*
Bài tập 1: Cho danh sách G gồm 4 chiếc ghế gán nhãn lần lượt là {‘A’, ‘B’, ‘C’, ‘D’}
và danh sách N gồm 4 người là {Tung, Cuc, Truc, Mai}.
- Thiết kế thuật toán A1 để liệt kê tất cả các cách xếp 4 người trong danh sách N 
vào 4 chiếc ghế trong danh sách G bằng phương pháp sinh.
- Thiết kế thuật toán A2 để liệt kê tất cả các cách xếp 4 người trong danh sách N 
vào 4 chiếc ghế trong danh sách G bằng phương pháp quay lui.
- Cài đặt chương trình thực hiện:
o Cài đặt các hàm biểu diễn các thuật toán A1 và A2.
o Khởi tạo các danh sách G và N.
o Áp dụng lần lượt các thuật toán A1 và A2 để liệt kê và hiển thị ra màn 
hình tất cả các cách xếp 4 người trong danh sách N vào 4 ghế trong danh 
sách G, mỗi cách xếp cần chỉ rõ vị trí ngồi (nhãn ghế) của mỗi người (tên 
người), cho biết tổng số cách xếp.
- So sánh cách thực hiện của hai phương pháp 
*/

#include<bits/stdc++.h>
using namespace std;

int x[4];
int dd[4] = {0};

// Thuat toan A1 - phuong phap sinh hoan vi
void swap(int &a, int &b) {
    int tmp = a;
    a = b; b = tmp;
}

void view_config(int x[], int n, char G[], string N[]) {
    for(int i = 1; i <= n; i++) {
        cout << N[x[i] - 1] << " duoc xep vao ghe " << G[i - 1] << endl;
    }
    cout << endl;
}

void next_config(int x[], int n, int i){
    int k = n;
    while(x[k] < x[i]) {
        k--;
    }

    swap(x[k], x[i]);

    int j = n; i++;

    // dao nguoc doan cuoi giam dan -> tang dan
    while(i < j) {
        swap(x[i], x[j]);
        i++; j--;
    }    
}

void list_config(int n, char G[], string N[]) {
    int count_config = 0;
    int i;
    int x[n+1] = {0};

    // dat cau hinh dau tien
    for(int i = 1; i <= n; i++) {
        x[i] = i;
    }

    do {
        view_config(x, n, G, N);
        i = n-1;

        // tim phan tu x[i] lien truoc doan cuoi giam dan
        while(i > 0 && x[i] > x[i+1]) {
            i--;
        }

        if(i>0) {
            next_config(x, n, i);
            count_config++;
        }
    }while(i > 0);

    cout << "So cau hinh la " << count_config + 1 << endl;
}



// Thuat toan A2 - quay lui
void backTracking(int k, int n, int dd[], char G[], string N[]) {
    // duyet qua cac phan tu cua tap S
    for(int i=1; i<=n; i++) {
        // neu chap nhan duoc
        if(dd[i] == 0) {
            // chon i cho x[k]
            x[k] = i;
            // neu la cau hinh cuoi thi in ra cau hinh
            if(k == n) {
                view_config(x, n, G, N);
            }else{
                dd[i] = 1;
                backTracking(k+1, n, dd, G, N);
                dd[i] = 0;
            }
        }
    }
}


int main() {
    int n = 4;
    char G[4] = {'A', 'B', 'C', 'D'};
    string N[4] = {"Tung", "Cuc", "Truc", "Mai"};

    cout << "===== Liet ke theo thuat toan A1 =====" << endl;
    list_config(n, G, N);

    int backCount = 0;
    cout << "\n===== Liet ke thi thuat toan A2 =====" << endl;
    backTracking(1, n, dd, G, N);
}