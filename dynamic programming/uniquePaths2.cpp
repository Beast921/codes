#include<iostream>
#include<vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> dp(n, 1);
    int o=0;
    for(;o<n;++o)
        if(obstacleGrid[0][o])
            break;
    for(;o<n;++o)
        dp[o] = 0;
    for(int i=1;i<m;++i){
        dp[0] = obstacleGrid[i][0] ? 0 : dp[0];
        for(int j=1;j<n;++j)
            dp[j] = obstacleGrid[i][j] ? 0 : dp[j-1] + dp[j];
    }
    return dp[n-1];
}

int main() {
    vector<vector<int>> v({{0,0,0},{0,1,0},{0,0,0}});
    cout<<uniquePathsWithObstacles(v);
    return 0;
}