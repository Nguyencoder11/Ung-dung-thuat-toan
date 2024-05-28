#include<bits/stdc++.h>
using namespace std;

/*
Input: Cho danh sách d chứa thông tin về n chủ đề hội thảo khác nhau được tổ chức trong 
một ngày, thông tin về mỗi hội thảo gồm: chủ đề (ví dụ: tìm kiếm việc làm, nâng cao kỹ năng 
mềm,…), thời gian bắt đầu, thời gian kết thúc.
Output: Tính k và s lần lượt là số lượng và danh sách nhiều nhất các hội thảo trong d mà một 
người có thể tham dự.
Yêu cầu thực hiện
- Thiết kế thuật toán T1 để tính và trả về k và s.
- Cài đặt chương trình gồm:
- Khởi tạo n và danh sách d.
- Cài đặt hàm biểu diễn thuật toán T1.
- Sử dụng thuật toán T để tính và trả về k và s. Thông báo kết quả
*/

struct Seminar {
    string topic;
    int start;
    int end;
    Seminar(string t, int s, int e) : topic(t), start(s), end(e) {}
};

bool compareByTimeEnd(const Seminar &a, const Seminar &b) {
    return a.end < b.end;
}

pair<int, vector<Seminar>> maxSeminars(vector<Seminar> &seminars){
    sort(seminars.begin(), seminars.end(), compareByTimeEnd);

    int endTime = 0;
    vector<Seminar> selectedSeminars;

    for(Seminar seminar : seminars){
        if(seminar.start > endTime){
            selectedSeminars.push_back(seminar);
            endTime = seminar.end;
        }
    }

    return {selectedSeminars.size(), selectedSeminars};
}

int main(){
    int n = 5;
    vector<Seminar> seminars = {
        {"Finding a Job", 9, 10},
        {"Improving Soft Skills", 10, 12},
        {"Career Development", 11, 13},
        {"Networking Tips", 13, 14},
        {"Work-Life Balance", 14, 15}
    };

    auto result = maxSeminars(seminars);
    int k = result.first;
    vector<Seminar> s = result.second;

    cout << "So luong hoi thao nhieu nhat co the tham du: " << k << endl;
    cout << "Danh sach cac hoi thao:" << endl;
    for(Seminar semi : s){
        cout << "Chu de: " << semi.topic << " - Bat dau: " << semi.start << " - Ket thuc: " << semi.end << endl;
    }
}