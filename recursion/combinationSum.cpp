#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve(vector<int>& candidates, int target, vector<vector<int>>& comb, vector<int>& v, int i) {
    if(target == 0) {
        comb.push_back(v);
        return;
    }
    if(i==candidates.size() || target<0) return;
    v.push_back(candidates[i]);
    solve(candidates, target-candidates[i], comb, v, i);
    v.pop_back();
    solve(candidates, target, comb, v, i+1);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> comb;
    vector<int> v;
    solve(candidates, target, comb, v, 0);
    return comb;
}

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = combinationSum(candidates, target);
    for(auto a: ans) {
        for(auto i: a)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}