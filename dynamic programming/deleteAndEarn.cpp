#include<iostream>
#include<vector>
using namespace std;

int solveTab(vector<int>& v, int n) {
    if(n==1)
        return v[0];
    int a= v[0], b = max(v[0], v[1]);
    for(int i=2;i<n;++i){
        int incl = a + v[i];
        int excl = b;
        a = b;
        b = max(incl, excl);
    }
    return b;
}

int deleteAndEarn(vector<int>& nums) {
    vector<int> m(10001, 0);
    for(int i: nums){
        m[i]+=i;
    }
    return solveTab(m, m.size());
}

int main() {
    vector<int> v({3,4,2});
    cout<<deleteAndEarn(v);
    return 0;
}