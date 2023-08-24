#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
using namespace std;
using namespace std::chrono;

int solveRec(vector<int>& v, int n) {
    if(n<0)
        return 0;
    if(n==0)
        return v[0];
    int incl = solveRec(v, n-2) + v[n];
    int excl = solveRec(v, n-1);
    return max(incl, excl);
}

int solveMem(vector<int>& v, int n, vector<int>& dp) {
    if(n<0)
        return 0;
    if(n==0)
        return v[0];
    if(dp[n]==-1){
        int incl = solveMem(v, n-2, dp) + v[n];
        int excl = solveMem(v, n-1, dp);
        dp[n] = max(incl, excl);
    }
    return dp[n];
}

int solveTab(vector<int>& v, int n) {
    if(n==1)
        return v[0];
    
    // Without space optimization
    // vector<int> dp(n, 0);
    // dp[0] = v[0];
    // dp[1] = max(v[0], v[1]);
    // for(int i=2;i<n;++i){
    //     int incl = dp[i-2] + v[i];
    //     int excl = dp[i-1];
    //     dp[i] = max(incl, excl);
    // }
    // return dp[n-1];

    // Space optimization
    int a= v[0], b = max(v[0], v[1]);
    for(int i=2;i<n;++i){
        int incl = a + v[i];
        int excl = b;
        a = b;
        b = max(incl, excl);
    }
    return b;
}

int maxNonAdjSum(vector<int>& v) {
    int n = v.size();

    vector<int> first, second;
    for(int i=0;i<n;++i){
        if(i!=0)
            first.push_back(v[i]);
        if(i!=n-1)
            second.push_back(v[i]);
    }

    // Recursion
    // int ans = max(solveRec(first, n-1), solveRec(second, n-1));

    // Memoization
    // vector<int> dp(n+1, -1);
    // int ans = max(solveMem(first, n-1, dp), solveMem(second, n-1, dp));

    // Tabulation
    int ans = max(solveTab(first, n), solveTab(second, n));

    return ans;
}

int main() {
    vector<int> v({2,4,7,8});
    auto start = high_resolution_clock::now();
    cout<<maxNonAdjSum(v);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<endl<<duration.count()<<" microsecs";
    return 0;
}