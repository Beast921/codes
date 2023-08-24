#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(nums.size()), suff(nums.size());
    suff[nums.size()-1] = 1;
    int pref = 1;
    for(int i=nums.size()-2;i>=0;--i)
        suff[i] = suff[i+1] * nums[i+1];
    for(int i=0;i<nums.size();++i) {
        ans[i] = pref * suff[i];
        pref *= nums[i];
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,3,4};
    nums = productExceptSelf(nums);
    for(int i: nums)
        cout<<i<<" ";
    return 0;
}