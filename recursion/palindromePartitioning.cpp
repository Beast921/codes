#include<iostream>
#include<vector>
using namespace std;

bool isPalin(string s, int st, int en) {
    while(st<en) {
        if(s[st++] != s[en--]) return false;
    }
    return true;
}

void solve(string& s, vector<vector<string>>& res, int st, vector<string>& curr) {
    if(st>=s.length()) {
        res.push_back(curr);
        return;
    }
    for(int i=st;i<s.length();++i)
        if(isPalin(s, st, i)) {
            curr.push_back(s.substr(st, i-st+1));
            solve(s, res, i+1, curr);
            curr.pop_back();
        }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> curr;
    solve(s, res, 0, curr);
    return res;
}

int main() {
    string s = "aab";
    vector<vector<string>> res = partition(s);
    for(auto v: res) {
        for(auto r: v)
            cout<<r<<" ";
        cout<<"\n";
    }
    return 0;
}