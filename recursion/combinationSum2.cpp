#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve(vector<int>& candidates, int target, vector<vector<int>>& comb, vector<int>& v, int i) {
    if(target == 0) {
        comb.push_back(v);
        return;
    }
    for(int j=i;j<candidates.size();++j) {
        if(j>i && candidates[j]==candidates[j-1]) continue;
        if(candidates[j]>target) break;
        v.push_back(candidates[j]);
        solve(candidates, target-candidates[j], comb, v, j+1);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> comb;
    vector<int> v;
    solve(candidates, target, comb, v, 0);
    return comb;
}

int main() {
    vector<int> candidates = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int target = 30;
    vector<vector<int>> ans = combinationSum2(candidates, target);
    for(auto a: ans) {
        for(auto i: a)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}