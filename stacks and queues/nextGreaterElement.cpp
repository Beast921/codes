#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    unordered_map<int, int> mp;
    for(int i=nums2.size()-1;i>=0;--i) {
        while(!st.empty() && st.top()<=nums2[i])
            st.pop();
        if(st.empty()) mp[nums2[i]] = -1;
        else mp[nums2[i]] = st.top();
        st.push(nums2[i]);
    }
    for(int i=0;i<nums1.size();++i)
        nums1[i] = mp[nums1[i]];
    return nums1;
}

int main() {
    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
    nums1 = nextGreaterElement(nums1, nums2);
    for(auto i: nums1)
        cout<<i<<" ";
    return 0;
}