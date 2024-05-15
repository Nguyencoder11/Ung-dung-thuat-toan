#include<bits/stdc++.h>
using namespace std;

/*
Input:
- Cho một kho chứa n gói hàng được ghi số thứ tự từ 1 đến n.
- Các gói hàng có khối lượng lần lượt là m1, m2, ..., mn và kích thước lần lượt 
là k1, k2, ..., kn.
- Cho một chiếc ba lô có kích thước k. 
Output:
- Tính p và d lần lượt là tổng khối lượng và danh sách các gói hàng được chọn
để đưa và ba lô sao cho tổng khối lượng là nhỏ nhất và tổng kích thước của 
các gói hàng được chọn không vượt quá kích thước của ba lô.
Thực hiện các yêu cầu sau:
- Thiết kế thuật toán A6 để tính và trả về p và d lần lượt là tổng khối lượng và 
danh sách các gói hàng được chọn để đưa và ba lô sao cho tổng khối lượng là
nhỏ nhất và tổng kích thước của các gói hàng được chọn không vượt quá kích 
thước của ba lô.
- Cài đặt chương trình:
o Cài đặt hàm F6 biểu diễn thuật toán A6.
o Khởi tạo k, n, {m1, m2, ..., mn} và {k1, k2, ..., kn}.
o Sử dụng thuật toán A6 để tính và đưa ra p và d.
*/


// Khai bao cau truc du lieu cho 1 goi hang
struct GoiHang{
    float kl;    // khoi luong cua goi hang
    int kt;  // kich thuoc cua goi hang
};

bool compare(GoiHang a, GoiHang b){
    return a.kt > b.kt;
}

float ArrangeBag(int n, vector<GoiHang>& h, int K, vector<GoiHang>& pickedBag){
    float sumWeight = 0;

    // sap xep danh sach cac goi hang theo kich thuoc giam
    sort(h.begin(), h.end(), compare);

    for(int i = 0; i < n; i++){
        if(K >= h[i].kt){
            sumWeight += h[i].kl;
            K -= h[i].kt;
            pickedBag.push_back(h[i]);
        }
    }

    return sumWeight;
}

int main(){
    // khai bao so goi hang
    int n;
    // khai bao kich thuoc ba lo
    int K;
    // khai bao danh sach cac goi hang
    vector<GoiHang> h(n);
    vector<GoiHang> pickedBag;

    cout << "So goi hang: "; cin >> n;
    cout << "Kich thuoc ba lo K = "; cin >> K;
    cout << "Danh sach cac goi hang voi khoi luong m va kich thuoc k tuong ung:" << endl;
    
    for(int i = 0; i < n; i++) {
        cin >> h[i].kl >> h[i].kt;
    }

    float p = ArrangeBag(n, h, K, pickedBag);
    cout << "Tong khoi luong cua cac goi hang duoc chon: " << p << endl;
    
    cout << "Cac goi hang duoc lay la: ";
    for (GoiHang g : pickedBag) {
        cout << "[kl: " << g.kl << ", kt: " << g.kt << "] ";
    }
}