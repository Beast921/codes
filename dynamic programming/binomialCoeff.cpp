#include<iostream>
#include<vector>
using namespace std;

int mod = 1e9+7;
int nCr(int n, int r){
    if(r>n)
        return 0;
    vector<int> dp(r+1, 0);
    dp[0] = 1;
    for(int i=1;i<=n;++i)
        for(int j=min(r, i);j>0;--j)
            dp[j] = (dp[j] + dp[j-1])%mod;
    return dp[r];
}

int main() {
    cout<<nCr(4, 2);
    return 0;
}