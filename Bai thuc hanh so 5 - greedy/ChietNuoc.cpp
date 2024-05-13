#include<bits/stdc++.h>
using namespace std;

/*
Input:
- Cho một bình có dung tích d chứa đầy nước và n chiếc chai rỗng có dung tích 
khác nhau để chiết nước từ bình vào đầy các chai.
- Dung tích lần lượt của các chai là x1, x2, ..., xn.
Output:
- Tính q là số lượng chai tối đa được đổ đầy nước.
Thực hiện các yêu cầu sau:
- Thiết kế thuật toán A2 để tính q là số lượng chai tối đa được đổ đầy nước bằng 
chiến lược tham lam.
- Cài đặt chương trình:
o Cài đặt hàm F2 biểu diễn thuật toán A2.
o Khởi tạo d và {x1, x2, ..., xn}.
o Sử dụng thuật toán A2 để tính và đưa ra q
*/

int maxFilledBottles(int d, vector<int>& bottles, vector<int>& filledBottle){
    sort(bottles.begin(), bottles.end());   // sap xep cac chai theo dung tich tang 
    int filledBottles = 0;
    int water = d;

    for(int i=0; i<bottles.size(); i++){
        if(water >= bottles[i]){
            filledBottles++;
            water -= bottles[i];
            filledBottle.push_back(bottles[i]);
        }else{
            break;
        }
    }

    return filledBottles;
}


int main(){
    int d = 10;
    int n = 5;
    vector<int> bottles = {8, 5, 4, 3, 2};
    vector<int> filledBottle;   // danh sach luu tru cac chai duoc do day nuoc (lit)

    int q = maxFilledBottles(d, bottles, filledBottle);
    cout << "So luong chai toi da co the do day nuoc la " << q << endl;

    cout << "Cac chai duoc do day nuoc la: ";
    for(int bottle : filledBottle){
        cout << bottle << " ";
    }
}