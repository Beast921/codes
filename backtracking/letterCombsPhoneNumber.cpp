#include<iostream>
#include<vector>
using namespace std;

vector<string> but = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void solve(string& digits, vector<string>& ans, string str, int n) {
    if(n == digits.length()) {
        if(str.length()) ans.push_back(str);
        return;
    }
    for(int i=0;i<but[digits[n]-'2'].length();++i)
        solve(digits, ans, str+but[digits[n]-'2'][i], n+1);
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    solve(digits, ans, "", 0);
    return ans;
}

int main() {

    string digits = "23";
    vector<string> res = letterCombinations(digits);
    for(auto s: res)
        cout<<s<<" ";
    return 0;
}