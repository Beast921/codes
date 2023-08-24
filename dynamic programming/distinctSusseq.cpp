#include<iostream>
#include<vector>
using namespace std;

int solveMem(string s, string t, int i, int j, vector<vector<int>>& dp) {
    if(j<0)
        return 1;
    if(i < j)
        return 0;
    if(dp[i][j] == -1){
        int incl = 0;
        if(s[i] == t[j])
            incl = solveMem(s, t, i-1, j-1, dp);
        int excl = solveMem(s, t, i-1, j, dp);
        dp[i][j] = incl + excl;
    }
    return dp[i][j];
}

int numDistinct(string s, string t) {
    vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
    return solveMem(s, t, s.length()-1, t.length()-1, dp);
}

int main() {
    cout<<numDistinct("babgbag", "bag");
    return 0;
}