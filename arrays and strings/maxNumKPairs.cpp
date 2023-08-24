#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int i=0, j=nums.size()-1, ans=0;
    while(i < j) {
        int sum = nums[i]+nums[j];
        if(sum == k)
            ++ans, ++i, --j;
        else if(sum < k) ++i;
        else --j;
    }
    return ans;
}

int main() {
    vector<int> nums = {3,1,3,4,3};
    int k = 6;
    cout<<maxOperations(nums, k)<<'\n';
    nums = {1,2,3,4};
    k = 5;
    cout<<maxOperations(nums, k);
    return 0;
}