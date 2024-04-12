/*
Bài tập 2: Cho tập S gồm 7 ký tự S = {‘A’, ‘B’, ‘C’, ‘D’, ‘E’, ‘F’, ‘G’}. 
- Thiết kế thuật toán A3 để liệt kê tất cả các lấy 6 ký tự trong danh sách S bằng 
phương pháp sinh.
- Thiết kế thuật toán A4 để liệt kê tất cả các cách lấy 6 ký tự trong danh sách S
bằng phương pháp quay lui.
- Cài đặt chương trình thực hiện:
o Khởi tạo danh sách S.
o Áp dụng lần lượt các thuật toán A3 và A4 để liệt kê và hiển thị ra màn 
hình tất cả các cách lấy 6 ký tự trong danh sách S.
- So sánh cách thực hiện của 2 phương pháp.
*/

#include<bits/stdc++.h>
using namespace std;

int x[7];
int dd[7] = {0};

// Thuat toan A3 - liet ke cac tap con
void view_config(int x[], int k, char S[]) {
    for(int i=1; i<=k; i++){
        cout << S[x[i] - 1] << " ";
    }
    cout << endl;
}

void next_config(int x[], int k, int i){
    // tim dc x[i] -> tang x[i] 1 don vi
    x[i] += 1;
    i++;
    while(i <= k){
        x[i] = x[i-1] + 1;
        i++;
    }
}

void list_config(int k, int n, char S[]){
    int i;
    int x[n+1] = {0};
    // khoi tao cau hinh dau tien
    for(int i=1; i<=k; i++){
        x[i] = i;
    }

    do {
        view_config(x, k, S);
        // tim phan tu chua dat gioi han tren
        i = k;
        while(i>0 && x[i]==n-k+i){
            i--;
        }
        if(i>0){
            next_config(x, k, i);
        }
    }while(i>0);
}



// Thuat toan A4 - quay lui
void backTracking(int trial, int k, int n, int dd[], char S[]){
    for(int i=1; i<=n; i++){
        if(dd[i] == 0){
            x[trial] = i;
            if(trial == k) {
                view_config(x, k ,S);
            }else{
                dd[i] = 1;
                backTracking(trial+1, k, n, dd, S);
                dd[i] = 0;
            }
        }
    }
}


int main() {
    int n = 7;
    int k = 6;
    char S[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

    cout << "===== Liet ke theo thuat toan A3 =====" << endl;
    list_config(k, n, S);

    cout << "\n===== Liet ke thi thuat toan A4 =====" << endl;
    backTracking(1, k, n, dd, S);
}