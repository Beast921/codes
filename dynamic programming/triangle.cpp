#include<iostream>
#include<vector>
using namespace std;

// int solveMem(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {
//     if(i==triangle.size())
//         return 0;
//     if(dp[i][j]==-1){
//         dp[i][j] = min(solveMem(triangle, i+1, j, dp), solveMem(triangle, i+1, j+1, dp)) + triangle[i][j];
//     }
//     return dp[i][j];
// }

int minimumTotal(vector<vector<int>>& triangle) {
    // vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
    // return solveMem(triangle, 0, 0, dp);
    for(int i=triangle.size()-2;i>=0;--i){
        for(int j=0;j<triangle[i].size();++j)
            triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
    }
    return triangle[0][0];
}

int main() {
        vector<vector<int>> v({{2},{3,4},{6,5,7},{4,1,8,3}});
    cout<<minimumTotal(v);
    return 0;
}