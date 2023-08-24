#include<iostream>
#include<vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size(), n=grid[0].size();
    vector<int> dp(n, 0);
    dp[0] = grid[0][0];
    for(int i=1;i<n;++i)
        dp[i] = dp[i-1] + grid[0][i];
    for(int i=1;i<m;++i){
        dp[0] += grid[i][0];
        for(int j=1;j<n;++j)
            dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
    }
    return dp[n-1];
}

int main() {
    vector<vector<int>> v({{1,3,1},{1,5,1},{4,2,1}});
    cout<<minPathSum(v);
    return 0;
}