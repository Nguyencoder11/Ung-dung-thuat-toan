/*
Cho danh sach b chứa thông tin về n chuyến bay của 1 hãng hàng không, thông 
tin về mỗi chuyến bay gồm số hiệu chuyến bay (ví dụ: VN005), giá vé, số ghế ngồi.
2
- Thiết kế thuật toán A1 để hiển thị ra màn hình tất cả các chuyến bay có giá vé 
trên 700000 bằng phương pháp đệ quy.
- Thiết kế thuật toán A2 để tìm và trả về chuyến bay có giá vé thấp nhất trong danh 
sách b bằng chiến lược chia để trị.
- Thiết kế thuật toán A3 để liệt kê tất cả các phương án khác nhau để chọn ra 4 
chuyến bay từ danh sách b bằng phương pháp quay lui.
- Viết chương trình thực hiện.
o Khởi tạo số nguyên dương n sao cho 6 ≤ n ≤ 10. Khởi tạo danh sách b gồm 
từ n chuyến bay, sao cho các chuyến bay có giá vé khác nhau đôi một
(không nhập dữ liệu từ bàn phím, dữ liệu có tính thực tiễn).
o Cài đặt các hàm biểu diễn các thuật toán A1, A2, A3.
o Áp dụng thuật toán A1 để hiển thị ra màn hình tất cả các chuyến bay trong 
danh sách b có giá vé trên 700000.
o Áp dụng thuật toán A2 để tìm chuyến bay có giá vé thấp nhất trong danh 
sách b, hiển thị thông tin đầy đủ của chuyến bay tìm được.
o Áp dụng thuật toán A3 để hiển thị ra màn hình tất cả các phương án chọn 
ra 4 chuyến bay từ danh sách b, mỗi chuyến bay cần hiển thị số hiệu 
chuyến bay và số ghế ngồi.
*/

#include<bits/stdc++.h>
using namespace std;

struct Flight{
    string soHieu;
    long giaVe;
    int soGhe;
};

void hienthi(Flight b[], int n) {
    cout << setw(10) << "So hieu" << setw(15) << "Gia ve" << setw(12) << "So ghe" << endl;
    for(int i=0; i<n; i++){
        cout << setw(10) << b[i].soHieu << setw(15) << b[i].giaVe << setw(12) << b[i].soGhe << endl;
    }
}

// Ham bieu dien thuat toan A1
void hienThiGiaVeTren700000(Flight b[], int n, int i=0) {
    if(i==n) return;
    if(b[i].giaVe > 700000) {
        cout << setw(10) << b[i].soHieu << setw(15) << b[i].giaVe << setw(12) << b[i].soGhe << endl;
    }
    hienThiGiaVeTren700000(b, n, i+1);
}

// Ham bieu dien thuat toan A2
Flight chuyenBayGiaVeThapNhat(Flight b[], int l, int r) {
    if(l == r) return b[l];

    int mid = l + (r-l)/2;

    Flight left = chuyenBayGiaVeThapNhat(b, l, mid);
    Flight right = chuyenBayGiaVeThapNhat(b, mid+1, r);

    return (left.giaVe < right.giaVe) ? left : right;
}

// Ham bieu dien thuat toan A3
void backTrackFlight(Flight b[], int n, vector<Flight>& selectedFlights, int start=0){
    // Neu da du 4 chuyen bay thi hien thi len man hinh
    if(selectedFlights.size() == 4){
        cout << "Phuong an chon 4 chuyen bay: " << endl;
        cout << setw(10) << "So hieu" << setw(15) << "Gia ve" << setw(12) << "So ghe" << endl;
        for(const auto& flight : selectedFlights) {
            cout << setw(10) << flight.soHieu << setw(15) << flight.giaVe << setw(12) << flight.soGhe << endl;
        }
        cout << endl;
        return;
    }

    for(int i=start; i<n; i++) {
        selectedFlights.push_back(b[i]);
        backTrackFlight(b, n, selectedFlights, i+1);
        selectedFlights.pop_back();
    }
}

int main(){
    int n;
    Flight b[6] = {
        {"VN01", 700000, 100},
        {"VN02", 600000, 90},
        {"VN03", 800000, 70},
        {"VN04", 200000, 80},
        {"VN05", 500000, 95},
        {"VN06", 900000, 85}
    };
    n = sizeof(b)/sizeof(b[0]);

    cout << "===== DANH SACH CAC CHUYEN BAY =====" << endl;
    hienthi(b, n);


    cout << "\n===== CAC CHUYEN BAY CO GIA VE TREN 700000 =====" << endl;
    hienThiGiaVeTren700000(b, n);

    cout << "\n===== CHUYEN BAY CO GIA VE THAP NHAT =====" << endl;
    Flight minFlight = chuyenBayGiaVeThapNhat(b, 0, n-1);
    cout << setw(10) << "So hieu" << setw(15) << "Gia ve" << setw(12) << "So ghe" << endl;
    cout << setw(10) << minFlight.soHieu << setw(15) << minFlight.giaVe << setw(12) << minFlight.soGhe << endl;

    cout << "\n===== CACH CHON 4 CHUYEN BAY TU DANH SACH =====" << endl;
    vector<Flight> selectedFlights;
    backTrackFlight(b, n, selectedFlights);
}