#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> v;
    sort(nums.begin(), nums.end());
    set<vector<int>> ans;
    int n = nums.size();
    for(int i=0; i<n; i++)
    {
        int a=nums[i];
        int s=i+1, e=n-1, j=0;
        while(s<e)
        {
            if(nums[s]+nums[e]==-a)
            {
                ans.insert({nums[i], nums[s], nums[e]});
                s++;
                e--;
                j++;
            }
            else if(nums[s]+nums[e]>-a)
            {
                e--;
            }
            else 
            {
                s++;
            }
        }
    }
    for(auto f: ans)
        v.push_back(f);
    return v;
}

int main() {
    vector<int> v ={-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum(v);
    for(auto a: ans){
        for(auto i: a)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}