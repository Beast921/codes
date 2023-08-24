#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int solveMem(int amount, vector<int>& coins, vector<vector<int>>& dp, int n) {
    if(amount==0)
        return 1;
    if(n==0)
        return 0;
    if(dp[n][amount]==-1){
        dp[n][amount] = solveMem(amount, coins, dp, n-1);
        if(amount-coins[n-1]>=0)
            dp[n][amount] += solveMem(amount-coins[n-1], coins, dp, n);
    }
    return dp[n][amount];
}

int solveTab(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<int> dp(amount+1, 0);
    dp[0] = 1;
    for(int i=1;i<=amount;++i)
        dp[i] = 0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=amount;++j){
            if(j-coins[i-1]>=0)
                dp[j] += dp[j-coins[i-1]];
        }
    }
    return dp[amount];                
}

int change(int amount, vector<int>& coins) {
    // vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
    // return solveMem(amount, coins, dp, coins.size());

    return solveTab(amount, coins);
}

int main() {
    vector<int> v = {1,2,5};
    int amt = 5;
    cout<<change(amt, v);
    return 0;
}