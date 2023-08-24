#include<iostream>
#include<vector>
using namespace std;

#define mod 1000000007;

long int solveRec(int n) {
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    return ((n-1)*(solveRec(n-1)+solveRec(n-2)))%mod;
}

long int solveMem(int n, vector<long int>& dp) {
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    if(dp[n]==-1)
        dp[n] = ((n-1)*(solveMem(n-1, dp)+solveMem(n-2, dp)))%mod;
    return dp[n];
}

long int solveTab(int n) {
    // vector<long int> dp(n+1, -1);
    // dp[0] = dp[1] = 0;
    // dp[2] = 1;
    // for(int i=3;i<=n;++i){
    //     dp[i] = ((i-1)*(dp[i-1]+dp[i-2]))%mod;
    // }
    // return dp[n];
    
    // Space Optimization
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    long int a = 0, b = 1;
    for(int i=3;i<=n;++i){
        long int c = ((i-1)*(b+a))%mod;
        a = b;
        b = c;
    }
    return b;
}

long int countDerangements(int n) {
    //Recursion
    // return solveRec(n);
    
    // Memoization
    // vector<long int> dp(n+1, -1);
    // return solveMem(n, dp);

    // Tabulation
    return solveTab(n);
}

int main() {
    int n = 5;
    cout<<countDerangements(n);
    return 0;
}