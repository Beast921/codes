#include<bits/stdc++.h>
using namespace std;

bool solve(string s, unordered_set<string>& m,  unordered_map<string, bool>& dp) {
    if(s.length() == 0)
        return true;
    if(dp.find(s) != dp.end())
        return dp[s];
    for(int i=0;i<s.length();++i) 
        if(m.count(s.substr(0, i+1)))
            if(solve(s.substr(i+1), m, dp))
                return dp[s] = true;
    return dp[s] = false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, bool> dp;
    unordered_set<string> m;
    for(string w: wordDict)
        m.insert(w);
    return solve(s, m, dp);
}

int main() {
    vector<string> wordDict = {"leet", "code"};
    string s = "leetcode";
    if(wordBreak(s, wordDict))
        cout<<"True";
    else
        cout<<"False";
    return 0;
}