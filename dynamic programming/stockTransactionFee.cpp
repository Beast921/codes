#include<iostream>
#include<vector>
using namespace std;

int solveMem(vector<int>& prices, int i, int buy, vector<vector<int>>& dp, int& fee) {
    if(i>=prices.size())
        return 0;
    if(dp[i][buy]==-1) {
        if(buy)
            dp[i][buy] = max(solveMem(prices, i+1, 0, dp, fee)-prices[i], solveMem(prices, i+1, buy, dp, fee));
        else
            dp[i][buy] = max(solveMem(prices, i+1, 1, dp, fee)+prices[i] - fee, solveMem(prices, i+1, buy, dp, fee));
    }
    return dp[i][buy];
}

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    if(n<2)
        return 0;
    // vector<vector<int>> dp(n+1, vector<int>(2, -1));
    // return solveMem(prices, 0, 1, dp, fee);

    vector<int> next(2, 0), curr(2,0);
    int buy = 0, sell = 0;
    for(int i=n-1;i>=0;--i){
        // int a = max(sell-prices[i], buy);
        // sell = max(buy+prices[i] - fee, sell);
        // buy = a;
        curr[1] = max(-prices[i] + next[0], next[1]);
        curr[0] = max(prices[i] + next[1] - fee, next[0]);
        next = curr;
    }
    return curr[1];
}

int main() {
    vector<int> v = {1,3,2,8,4,9};
    int fee = 2;
    cout<<maxProfit(v, fee);
    return 0;
}