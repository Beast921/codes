#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void solve(vector<int>& nums, int i, vector<int>& v, set<vector<int>>& ans) {
    if(i == nums.size()) {
        ans.insert(v);
        return;
    }
    solve(nums, i+1, v, ans);
    v.push_back(nums[i]);
    solve(nums, i+1, v, ans);
    v.pop_back();
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>> ans;
    vector<int> v;
    sort(nums.begin(), nums.end());
    solve(nums, 0, v, ans);
    vector<vector<int>> res;
    for(auto a: ans)
        res.push_back(a);
    return res;
}

int main() {
    vector<int> nums = {1,2,2};
    vector<vector<int>> ans = subsetsWithDup(nums);
    for(auto v: ans) {
        for(auto i: v)
            cout<<i<<", ";
        cout<<"\n";
    }
    return 0;
}