#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& cost, int n, vector<int>& dp){
    if(n==0)
        return cost[0];
    if(n==1)
        return cost[1];
    if(dp[n]==-1)
        dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
    return dp[n];
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n+1, -1);
    return min(solve(cost, n-1, dp), solve(cost, n-2, dp));
}

int main() {
    int n;
    cin>>n;
    vector<int> v;
    while(n--){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<minCostClimbingStairs(v);
    return 0;
}   