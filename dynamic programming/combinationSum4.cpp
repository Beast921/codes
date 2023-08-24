// Number of ways target can be achieved

#include<iostream>
#include<vector>
using namespace std;

int solveMem(vector<int>& v, int tar, vector<int>& dp) {
    if(tar==0)
        return 1;
    if(tar<0)
        return 0;
    if(dp[tar]==-1){
        dp[tar] = 0;
        for(int i: v)
            dp[tar] += solveMem(v, tar-i, dp);
    }
    return dp[tar];
}   

int solveTab(vector<int>& v, int tar) {
    vector<long long int> dp(tar+1, 0);
    dp[0] = 1;
    for(int i=1;i<=tar;++i){
        auto c = 0;
        for(int j=0;j<v.size();++j)
            if(i-v[j]>=0)
                c += (dp[i-v[j]]%1000000007);
        dp[i] = c;
    }
    return dp[tar];
}

int combSum4(vector<int>& v, int tar) {
    // vector<int> dp(tar+1, -1);
    // return solveMem(v, tar, dp);

    return solveTab(v, tar);
}

int main() {
    vector<int> v({1,2,3});
    int tar = 4;
    cout<<combSum4(v, tar);
    return 0;
}