#include<iostream>
#include<vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
    int mx = 0;
    for(int i=1;i<dp.size();++i)
        for(int j=1;j<dp[0].size();++j)
            if(matrix[i-1][j-1]=='1'){
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                mx = max(mx, dp[i][j]);
            }
    return mx*mx;
}

int main() {
    vector<vector<char>> v({{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}});
    cout<<maximalSquare(v);
    return 0;
}