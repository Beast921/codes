#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveMem(int n, vector<int>& dp) {
    if(n==0)
        return 0;
    if(dp[n]==-1){
        int res = n;
        for(int i=1;i*i<=n;++i)
            res = min(res, solveMem(n-i*i, dp));
        dp[n] = res;
    }
    return 1+dp[n];
}

int solveTab(int n) {
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for(int j=1;j<=n;++j){
        int res = j;
        for(int i=1;i*i<=j;++i)
            res = min(res, dp[j-i*i]);
        dp[j] = 1+res;
    }
    return dp[n];
}

int numSquares(int n) {
    // vector<int> dp(n+1, -1);
    // return solveMem(n, dp);

    return solveTab(12);
}

int main() {
    cout<<numSquares(5);
    return 0;
}