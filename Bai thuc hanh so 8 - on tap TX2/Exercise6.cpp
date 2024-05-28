#include<bits/stdc++.h>
using namespace std;

/*
Input: Cho một danh sách d gồm n xâu ký tự, mỗi xâu ký tự là một câu tiếng anh có chiều 
dài không quá 100 ký tự, các xâu ký tự đôi một khác nhau. 
Output: Tạo một xâu ký tự mới p có độ dài đúng bằng k bằng cách nối các xâu ký tự lấy từ
danh sách d sao cho số xâu ký tự cần lấy trong danh sách d là ít nhất.
Yêu cầu thực hiện
- Thiết kế một thuật toán G để tạo và trả về xâu p.
- Cài đặt chương trình thực hiện:
o Khởi tạo số k, n và danh sách d (5 ≤ n ≤ 10).
o Cài đặt hàm biểu diễn thuật toán G.
o Sử dụng thuật toán G để tạo xâu p. Thông báo kết quả.
o Ứng dụng thuật toán Boyer Moore Horspool cho biết từ “child” xuất hiện trong 
bao nhiêu xâu của danh sách d, gồm những xâu nào (in các xâu xuất hiện từ
“child”)?
o Ứng dụng thuật toán Z cho biết xâu d[0] là xâu con của những xâu nào trong 
danh sách d (không tính d[0]), in các xâu chứa xâu d[0] và số lần xuất hiện d[0] trong mỗi xâu đó
*/

string createStringG(vector<string> &d, int k){
    string p;
    int currLen = 0;
    for(string str : d){
        if(currLen + str.length() > k){
            break;
        }
        p += str;
        currLen += str.length();
    }
    if(currLen < k){
        p += string(k - currLen, ' ');
    }

    return p;
}

bool BoyerMooreHorspool(const string &str, const string &pattern){
    int s = str.length();
    int p = pattern.length();

    if(p > s) return false;

    int i = 0;
    while(i++ <= s - p){
        int j = p - 1;
        while(j>=0 && pattern[j] == str[i+j]){
            j--;
        }
        if(j < 0) return true;
    }

    return false;
}

vector<int> ZAlgorithm(const string &s){
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    int k;
    for(int i=1; i<n; i++){
        if(i>r){
            l = r = i;
            while(r < n && s[r] == s[r-l]) r++;
            z[i] = r - l;
            r--;
        }else{
            k = i - l;
            if(z[k] < r-i+1){
                z[i] = z[k];
            }else{
                l = i;
                while(r < n && s[r] == s[r - l]) r++;
                z[i] = r - l;
                r--;
            }
        }
    }

    return z;
}

vector<int> findSubstrings(const string &s, const string &pattern) {
    string concat = pattern + "$" + s;
    vector<int> Z = ZAlgorithm(concat);
    vector<int> positions;
    int patternLength = pattern.length();
    for (int i = patternLength + 1; i < Z.size(); ++i) {
        if (Z[i] == patternLength) {
            positions.push_back(i - patternLength - 1);
        }
    }
    return positions;
}

int main(){
    int n = 5; // Số lượng xâu trong danh sách d
    int k = 100; // Độ dài xâu p

    vector<string> d = {
        "The child is now at the school.",
        "The quick brown fox jumps over the lazy dog.",
        "A journey of a thousand miles begins with a single step.",
        "To be or not to be, that is the question.",
        "When I was a child, I like playing soccer."
    };
    
    // su dung thuat toan G tao xau p tu cac xau trong danh sach d voi do dai la k
    string p = createStringG(d, k);
    cout << "Xau p: " << p << endl;

    // Tim so lan xuat hien tu "child" trong danh sach d bang tt BoyerMooreHorspool
    string keyword = "child";
    vector<string> containingChild;
    for(string str : d){
        if(BoyerMooreHorspool(str, keyword)){
            containingChild.push_back(str);
        }
    }
    cout << "So xau xuat hien tu 'child': " << containingChild.size() << endl;
    cout << "Cac xau xuat hien tu 'child':" << endl;
    for(string str : containingChild){
        cout << str << endl;
    }

    // Tim xau d[0] la xau con cua nhung xau nao trong danh sach d (khong tinh d[0])
    string pattern = d[0];
    vector<string> containingD0;
    for (int i = 1; i < d.size(); ++i) {
        vector<int> positions = findSubstrings(d[i], pattern);
        if (!positions.empty()) {
            containingD0.push_back(d[i]);
            cout << "Xau d[0] xuat hien trong xau: " << d[i] << " tai cac vi tri: ";
            for (int pos : positions) {
                cout << pos << " ";
            }
            cout << endl;
        }else{
            cout << "Xau d[0] khong xuat hien trong bat ky xau nao";
            break;
        }
    }
}