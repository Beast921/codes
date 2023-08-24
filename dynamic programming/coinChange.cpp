#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solve(vector<int>& coins, int x, vector<int>& dp){
    if(x==0)
        return 0;
    if(x<0)
        return INT_MAX;
    if(dp[x]==-1){
        int ans = INT_MAX;
        for(int i=0;i<coins.size();++i){
            int res = solve(coins, x-coins[i], dp);
            if(res!=INT_MAX)
                ans = min(ans, 1+res);
        }
        dp[x] = ans;
    }
    return dp[x];
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, -1);
    int ans = solve(coins, amount, dp);
    return ans==INT_MAX ? -1 : ans;
}

int main() {
    vector<int> coins({1,2,3});
    int amt = 8;
    cout<<coinChange(coins, amt);
    return 0;
}