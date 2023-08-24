#include<iostream>
#include<vector>
using namespace std;

int cntZero(string s) {
    int a = 0;
    for(char c: s)
        if(c == '0')
            ++a;
    return a;
}

int cntOne(string s) {
    int a = 0;
    for(char c: s)
        if(c == '1')
            ++a;
    return a;
}

int solveMem(vector<string>& strs, int l, int m, int n, vector<vector<vector<int>>>& dp) {
    if(l==0)
        return 0;
    if(dp[l][m][n] == -1) {
        int c0 = cntZero(strs[l-1]), c1 = cntOne(strs[l-1]);
        int incl = 0;
        if(m>=c0 && n>=c1)
            incl = 1 + solveMem(strs, l-1, m-c0, n-c1, dp);
        int excl = solveMem(strs, l-1, m, n, dp);
        dp[l][m][n] = max(incl, excl);
    }
    return dp[l][m][n];
}

int solveTab(vector<string>& strs, int m, int n) {
    int l = strs.size();
    // vector<vector<vector<int>>> dp(l+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
    // for(int i=1;i<=l;++i){
    //     int c0 = cntZero(strs[i-1]), c1 = cntOne(strs[i-1]);
    //     for(int j=0;j<=m;++j){
    //         for(int k=0;k<=n;++k){
    //             int incl = 0;
    //             if(j>=c0 && k>=c1)
    //                 incl = 1 + dp[i-1][j-c0][k-c1];
    //             int excl = dp[i-1][j][k];
    //             dp[i][j][k] = max(incl, excl);
    //         }
    //     }
    // }
    // return dp[l][m][n];

    vector<vector<int>> prev(m+1, vector<int>(n+1, 0)), curr(m+1, vector<int>(n+1, 0));
    for(int i=1;i<=l;++i){
        int c0 = cntZero(strs[i-1]), c1 = cntOne(strs[i-1]);
        for(int j=0;j<=m;++j){
            for(int k=0;k<=n;++k){
                int incl = 0;
                if(j>=c0 && k>=c1)
                    incl = 1 + prev[j-c0][k-c1];
                int excl = prev[j][k];
                curr[j][k] = max(incl, excl);
            }
        }
        prev = curr;
    }
    return prev[m][n];
}

int findMaxForm(vector<string>& strs, int m, int n) {
    // int l = strs.size();
    // vector<vector<vector<int>>> dp(l+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
    // return solveMem(strs, l, m, n, dp);

    return solveTab(strs, m, n);
}

int main() {
    vector<string> strs = {"10","0001","111001","1","0"};
    int m = 5, n = 3;
    cout<<findMaxForm(strs, m, n);
    return 0;
}