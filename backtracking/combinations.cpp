#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(int n, int k, vector<vector<int>>& ans, vector<int>& v) {
    if(!k) {
        ans.push_back(v);
        return;
    }
    for(int i=v.empty()?1:v.back();i<=n;++i)
        if(find(v.begin(), v.end(), i) == v.end()) {
            v.push_back(i);
            solve(n, k-1, ans, v);
            v.pop_back();
        }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> v;
    solve(n, k, ans, v);
    return ans;
}

int main() {
    vector<vector<int>> res = combine(4, 2);
    for(auto v: res) {
        for(auto i: v)
            cout<<i<<" ";
        cout<<'\n';
    }
    return 0;
}