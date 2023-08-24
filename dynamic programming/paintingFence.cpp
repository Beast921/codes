#include<iostream>
#include<vector>
using namespace std;

#define mod 1000000007

int add(int a, int b) {
    return (a%mod+b%mod)%mod;
}

int mul(int a, int b) {
    return ((a%mod)*(b%mod))%mod;
}

int solveMem(int n, int k, vector<int>& dp) {
    if(n==1)
        return k;
    if(n==2)
        return mul(k, k);
    if(dp[n]==-1) {
        dp[n] = add(mul(solveMem(n-2, k, dp), k-1), mul(solveMem(n-1, k, dp), k-1));
    }
    return dp[n];
}

int solveTab(int n, int k) {
    if(n==1)
        return k;
    int a = k, b = mul(k, k);
    for(int i=3;i<=n;++i) {
        int c = add(mul(a, k-1), mul(b, k-1));
        a = b;
        b = c;
    }
    return b;
}

int paintingFence(int n, int k) {
    // vector<int> dp(n+1, -1);
    // return solveMem(n, k, dp);

    return solveTab(n, k);
}

int main() {
    cout<<paintingFence(3, 2);
    return 0;
}