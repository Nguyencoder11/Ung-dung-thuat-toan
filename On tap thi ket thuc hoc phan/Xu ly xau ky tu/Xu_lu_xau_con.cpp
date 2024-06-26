#include<bits/stdc++.h>
using namespace std;

// Thuat toan vet can (lap)
int indexOf(const char *p, const char *t) {
    int m = strlen(p);
    int n = strlen(t) - m;
    for (int i = 0; i <= n; i++){
        int j = 0;
        while (j < m && t[i + j] == p[j]) {
            j++;
        }
        if (j == m)
            return i;
    }
    return -1;
}


// Thuat toan Boyer Moore Horspool kiem tra P co phai la xau con cua T
// va tim vi tri cua xau con P trong T (neu P la xau con)
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


// Thuat toan Z tim so xau con P trong xau T
void Algorithm_Z(const string& str, const string& word){
    string s = word + "$" + str;
    int len_s = s.length();
    vector<int> z(len_s, 0);
    int left = 0, right = 0;

    for(int i=1; i<len_s; i++){
        // truong hop 1: i > right
        if(i > right){
            left = right = i;
            while(right < len_s && s[right - left] == s[right]){
                right++;
            }
            z[i] = right - left; 
            right--;
        }
        // truong hop i < right
        else {
            int k = i - left;
            if(z[k] < right - i + 1){
                z[i] = z[k];
            }else{
                left = i;
                while(right < len_s && s[right - left] == s[right]) {
                    right++;
                }
                z[i] = right - left; 
                right--;
            }
        }
    }
}

int main() {

}