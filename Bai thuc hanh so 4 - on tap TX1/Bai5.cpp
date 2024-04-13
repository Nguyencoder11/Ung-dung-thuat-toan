/*
Cho danh sách c gồm n công việc cần thực hiện trong ngày của một công ty, 
thông tin về mỗi công việc gồm mã công việc, thời gian bắt đầu thực hiện, thời gian cần 
thiết để thực hiện công việc (số phút hoặc số giờ cần thiết để thực hiện công việc). Cũng 
cho danh sách L gồm tên của n nhân viên.
- Thiết kế thuật toán A1 để hiển thị ra màn hình tất cả các công việc trong danh 
sách c theo thứ tự ngược lại bằng phương pháp đệ quy.
- Thiết kế thuật toán A2 để đếm và trả về số công việc có thời gian thực hiện không 
quá 30 phút (hoặc 0.5 giờ) trong danh sách c bằng chiến lược chia để trị.
- Thiết kế thuật toán A3 để liệt kê tất cả các phương án khác nhau để giao n công 
việc trong danh sách c cho n nhân viên trong danh sách L bằng phương pháp 
sinh.
- Viết chương trình thực hiện.
o Khởi tạo số nguyên dương n sao cho 6 ≤ n ≤ 10. Khởi tạo danh sách c gồm 
n công việc và khởi tạo danh sách nhân viên L (không nhập dữ liệu từ bàn 
phím, dữ liệu có tính thực tiễn).
o Áp dụng thuật toán A1 để hiển thị danh sách các công việc trong danh 
sách c theo thứ tự ngược lại.
o Áp dụng thuật toán A2 để đếm số công việc trong danh sach c có thời gian thực 
hien không quá 30 phút, hiển thị kết quả (nếu có).
o Áp dụng thuật toán A3 để hiển thị tất cả các phương án khác nhau để giao 
n công việc trong danh sách c cho n nhân viên trong danh sách L, mỗi 
phương án hiển thị danh sách gồm tên công việc – tên nhân viên tương 
ứng
*/


#include<bits/stdc++.h>
using namespace std;

struct CongViec{
    string maCV;
    int thoiGianBatDau;
    int thoiGianThucHien;
};

void hienthi(CongViec c[], int n){
    cout << setw(20) << "Ma cong viec" << setw(20) << "Thoi gian start" << setw(20) << "Thoi gian can thiet" << endl;
    for(int i=0; i<n; i++){
        cout << setw(20) << c[i].maCV << setw(20) << c[i].thoiGianBatDau << setw(20) << c[i].thoiGianThucHien << endl;
    }
}

// Ham bieu dien thuat toan A1
void hienThiNguoc(CongViec c[], int n){
    if(n==0) return;
    cout << setw(20) << c[n-1].maCV << setw(20) << c[n-1].thoiGianBatDau << setw(20) << c[n-1].thoiGianThucHien << endl;
    hienThiNguoc(c, n-1);
}

// Ham bieu dien thuat toan A2
int demSoCongViec(CongViec c[], int l, int r){
    if(l>r) return 0;
    if(l==r) {
        if(c[l].thoiGianThucHien <= 30) return 1;
        else return 0;
    }

    int m = l + (r-l)/2;
    return demSoCongViec(c, l, m) + demSoCongViec(c, m+1, r);
}

// Ham bieu dien thuat toan A3
void backTrackPhanViec(CongViec c[], string L[], int n, int *isArranged, vector<pair<string, string>>& assignedJobs, int start=0){
    if(start == n){
        cout << "Phuong an giao viec:" << endl;
        for (auto p : assignedJobs) {
            cout << p.first << " - " << p.second << endl;
        }
        cout << endl;
        return;
    }

    for(int i=0; i<n; i++){
        if(isArranged[i] == 0){
            isArranged[i]=1;
            assignedJobs.push_back({c[start].maCV, L[i]});
            backTrackPhanViec(c, L, n, isArranged, assignedJobs, start+1);
            isArranged[i] = 0;
            assignedJobs.pop_back();
        }
    }
}



int main(){
    int n = 6;
    CongViec c[6] = {
        {"CV01", 6, 60},
        {"CV02", 7, 90},
        {"CV03", 8, 120},
        {"CV04", 9, 70},
        {"CV05", 5, 100},
        {"CV06", 3, 20}
    };
    string L[6] = {"Nam", "Lan", "Hoa", "Tuan", "Thao", "Duc"};

    cout << "===== DANH SACH CAC CONG VIEC =====" << endl;
    hienthi(c, n);

    cout << "\n===== DANH SACH CONG VIEC IN NGUOC =====" << endl;
    hienThiNguoc(c, n);

    cout << "\nSo cong viec co thoi gian hoan thanh duoi 30 phut: " << demSoCongViec(c, 0, n-1); 

    int isArranged[6] = {0};
    vector<pair<string, string>> assignedJobs;
    cout << "\n===== CAC PHUONG AN GIAO VIEC CHO NHAN VIEN =====" << endl;
    backTrackPhanViec(c, L, n, isArranged, assignedJobs);

}