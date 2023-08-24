#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveRec(vector<int>& weight, vector<int>& values, int n, int W) {
    if(n==0)
        if(weight[0] <= W)
            return values[0];
        else
            return 0;
    int incl = 0;
    if(weight[n] <= W)
        incl = values[n] + solveRec(weight, values, n-1, W-weight[n]);
    int excl = solveRec(weight, values, n-1, W);
    return max(incl, excl);
}

int solveMem(vector<int>& weight, vector<int>& values, int n, int W, vector<vector<int>>& dp) {
    if(n==0)
        if(weight[0] <= W)
            return values[0];
        else
            return 0;
    if(dp[n][W] == -1){
        int incl = 0;
        if(weight[n] <= W)
            incl = values[n] + solveMem(weight, values, n-1, W-weight[n], dp);
        int excl = solveMem(weight, values, n-1, W, dp);
        dp[n][W] = max(incl, excl);
    }
    return dp[n][W];
}

int solveTab(vector<int>& weight, vector<int>& values, int n, int W) {
    // vector<vector<int>> dp(n, vector<int>(W+1, -1));
    vector<int> curr(W+1, -1), prev(W+1, -1);
    for(int w=0;w<=W;++w)
        if(weight[0] <= w)
            prev[w] = values[0];
        else
            prev[w] = 0;
    for(int i=1;i<n;++i) {
        for(int w=0;w<=W;++w){
            int incl = 0;
            if(weight[i] <= w)
                incl = values[i] + prev[w-weight[i]];
            int excl = prev[w];
            curr[w] = max(incl, excl);
        }
        prev = curr;
    }
    return prev[W];
}

int knapsack(vector<int>& weight, vector<int>& values, int n, int W) {
    // return solveRec(weight, values, n-1, W);
    
    // vector<vector<int>> dp(n, vector<int>(W+1, -1));
    // return solveMem(weight, values, n-1, W, dp);

    return solveTab(weight, values, n-1, W);
}

int main() {
    vector<int> weight({1,2,4,5}), values({5,4,8,6});
    int n=4, W=5;
    cout<<knapsack(weight, values, n, W);
    return 0;
}