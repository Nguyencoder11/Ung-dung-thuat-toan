/*
Cho một số nguyên dương n ≥ 8, một dãy a gồm n số thực được sắp xếp theo 
chiều tăng dần, một số thực C và 2 chuỗi P và Q không quá 255 ký tự chỉ gồm các chữ số, 
chữ cái và dấu cách. Cài đặt chương trình thực hiện:
- Cài đặt thuật toán tham lam để tính D là số lượng phần tử ít nhất có thế lấy trong 
dãy a để được một giá trị M lớn hơn C và cho biết giá trị của các phần tử đã lấy
trong a (nếu có). Cài đặt thuật toán Boyer Moore Horspool cho biết vị trí xuất hiện 
chuỗi ký tự P trong chuỗi ký tự Q.
- Khởi tạo số nguyên dương n, mảng số thực a với các số theo chiều tăng dần, khởi 
tạo số C. Khởi tạo 2 chuỗi ký tự P và Q. Sử dụng các thuật toán đã cài đặt ở trên để
hiển thị ra màn hình các giá trị D, M, các giá trị đã lấy trong mảng a (nếu có phương 
án), thông báo vị trí xuất hiện chuỗi P trong chuỗi Q.
*/

#include<bits/stdc++.h>
using namespace std;

// Using greedy algorithm to count amounts of elements that are the most
pair<int, vector<double>> amountOfElements(const vector<double>& a, double C, double &M) {
    vector<double> selectedElements;

    for(double num : a) {
        if(M + num <= C) {
            selectedElements.push_back(num);
            M += num;
        } else {
            break;
        }
    }

    return {selectedElements.size(), selectedElements};
}

// Using Boyer-Moore-Horspool algorithm to check if Q is the subtring of P or not
bool isSubStringOf(const string &Q, const string &P) {
    int len_p = P.length();
    int len_q = Q.length();

    if(len_q > len_p) return false;

    vector<int> shift(256, len_q);
    for(int i = 0; i < len_q - 1; i++) {
        shift[Q[i]] = len_q - 1 - i;
    }

    int i=0;
    while(i <= len_p - len_q) {
        int j = len_q - 1;
        while(j >= 0 && Q[j] == P[i + j]){
            j--;
        }

        if(j < 0) return true;

        i += shift[P[i + len_q - 1]];
    }
    
    return false;
}

int main(){
    int n = 10;
    vector<double> a(n);
    a = {-15, -9, -3.2, -2.6, 0.5, 1, 2.5, 5.8, 7.8, 23};

    double C = 20.0;
    double M = 0;
    string P = "This is a test string 221";
    string Q = "test";

    auto result = amountOfElements(a, C, M);
    int D = result.first;
    vector<double> selectedElements = result.second;

    cout << "D: " << D << endl;
    cout << "M: " << M << endl;
    if(D > 0) {
        cout << "Selected Items: ";
        for(double num : selectedElements) {
            cout << num << ", ";
        }
        cout << endl;
    }

    if(isSubStringOf(P, Q)) {
        cout << "Q is a substring of P" << endl;
    } else {
        cout << "Q isn't a substring of P" << endl;
    }
}