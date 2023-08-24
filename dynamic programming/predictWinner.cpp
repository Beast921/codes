#include<iostream>
#include<vector>
using namespace std;

int compute(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
    if(l==r) return nums[l];
    if(dp[l][r] != -1) return dp[l][r];
    int left = nums[l] - compute(nums, l+1, r, dp);
    int right = nums[r] - compute(nums, l, r-1, dp);
    dp[l][r] = max(left, right);
    return dp[l][r];
}

bool PredictTheWinner(vector<int>& nums) {
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
    return compute(nums, 0, nums.size()-1, dp) >= 0;
}

int main() {
    vector<int> nums = {20, 5, 2};
    if(PredictTheWinner(nums))
        cout<<"True";
    else
        cout<<"False";
    return 0;
}