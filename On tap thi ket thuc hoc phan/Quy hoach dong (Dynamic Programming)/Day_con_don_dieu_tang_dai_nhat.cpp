#include<bits/stdc++.h>
using namespace std;

vector<double> longestIncreasingSubsequence(vector<double> &a){
    int n = a.size();

    if(n==0) return {};

    vector<int> dp(n,1);
    vector<int> prev(n,-1);

    // Tim do dai cua LIS tai moi vi tri
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[i] > a[j] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
                prev[i] = j;
            }
        }
    }

    // Tim do dai lon nhat cua LIS va vi tri ket thuc cua no
    int lis_length = 0;
    int lis_end = 0;
    for(int i=0; i<n; i++){
        if(dp[i] > lis_length){
            lis_length = dp[i];
            lis_end = i;
        }
    }

    // Truy vet tim day con tang dai nhat
    vector<double> lis;
    for(int i=lis_end; i>=0; i=prev[i]){
        lis.push_back(a[i]);
        if(prev[i] == -1) break;
    }
    reverse(lis.begin(), lis.end());

    return lis;
}

int main(){
    int n;
    cout << "Nhap so phan tu cua day: "; cin >> n; 
    vector<double> a(n);
    cout << "Nhap cac phan tu cua day a: ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<double> b = longestIncreasingSubsequence(a);

    cout << "Day con don dieu tang dai nhat: ";
    for(double value : b){
        cout << value << " ";
    }
    cout << endl;
}