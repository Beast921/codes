#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2)
        return n;

    int longest = 2;
    vector<unordered_map<int, int>> dp(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int diff = nums[i] - nums[j];
            dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
            longest = max(longest, dp[i][diff]);
        }
    }

    return longest;
}

int main() {
    vector<int> v = {9,4,7,2,10};
    cout<<longestArithSeqLength(v);
    return 0;
}