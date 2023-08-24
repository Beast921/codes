#include<iostream>
#include<vector>
using namespace std;

// int solveMem(int m , int n, vector<vector<int>>& dp) {
//     if(m<0 || n<0)
//         return 0;
//     if(m==0 && n==0)
//         return 1;
//     if(dp[m][n]==-1){
//         dp[m][n] = solveMem(m-1, n, dp)+solveMem(m, n-1, dp);
//     }
//     return dp[m][n];
// }

int solveTab(int m, int n) {
    vector<int> dp(n, 1);
    for(int i=1;i<m;++i)
        for(int j=1;j<n;++j)
            dp[j] = dp[j-1] + dp[j];
    return dp[n-1];
}

int uniquePaths(int m, int n) {
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    return solveTab(m, n);
}

int main() {
    cout<<uniquePaths(3, 2);
    return 0;
}