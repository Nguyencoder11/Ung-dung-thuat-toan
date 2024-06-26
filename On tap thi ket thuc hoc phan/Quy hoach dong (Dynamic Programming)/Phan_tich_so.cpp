#include<bits/stdc++.h>
using namespace std; 

int countPartitions(int n){
    // khoi tao mang dp
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    // cap nhat mang dp
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            dp[j] += dp[j-i];
        }
    }

    // so cach phan tich so n la dp[n]
    return dp[n];
}

int main(){
    int n;
    cout << "Nhap so tu nhien n: "; cin >> n;
    if(n<=0 || n>100){
        cout << "n phai la so tu nhien tu 1 den 100.";
        return 1;
    }

    int p = countPartitions(n);
    cout << "So cach phan tich " << n << " thanh tong cac so nguyen duong: " << p << endl;
}