#include<iostream>
#include<vector>
using namespace std;

int solve(int n, vector<int>& dp){
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(dp[n]==-1)
        dp[n] = solve(n-1, dp)+solve(n-2, dp);
    return dp[n];
}

int climbStairs(int n) {
    vector<int> dp(n+1, -1);
    return solve(n-1, dp)+solve(n-2, dp);
}

int main() {
    int n;
    cin>>n;
    cout<<climbStairs(n);
    return 0;
}