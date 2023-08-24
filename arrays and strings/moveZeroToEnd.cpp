#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    for(int i=0,j=0;i<nums.size();++i)
        if(nums[i])
            swap(nums[i], nums[j++]);
}

int main() {
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    for(int i: nums)
        cout<<i<<" ";
    return 0;
}