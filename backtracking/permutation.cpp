#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
    if(curr.size() == nums.size()) {
        ans.push_back(curr);
        return;
    }
    for(int n: nums)
        if(find(curr.begin(), curr.end(), n) == curr.end()) {
            curr.push_back(n);
            solve(nums, curr, ans);
            curr.pop_back();
        }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<int> curr;
    vector<vector<int>> ans;
    solve(nums, curr, ans);
    return ans;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = permute(nums);
    for(auto v: res) {
        for(auto i: v)
            cout<<i<<" ";
        cout<<'\n';
    }
    return 0;
}