#include <bits/stdc++.h> 
using namespace std;

string cmp(string s1, string s2) {
    for(int i=0;i<s1.length();++i)
        if(s1[i] < s2[i])
            return s1;
        else if(s2[i] < s1[i])
            return s2;
    return s1;
}

string completeString(vector<string> &a){
    string res="";
    for(string s: a) {
        if(s.length() < res.length()) continue;
        bool b = true;
        for(int i=1;b && i<s.length();++i)
            if(find(a.begin(), a.end(), s.substr(0, i)) == a.end())
                b = false;
        if(b) {
            if(s.length() > res.length())
                res = s;
            else
                res = cmp(s, res);
        }
    }
    return res.length() ? res : "None";
}

int main() {
    vector<string> s = {"a", "ab", "abc", "b", "bp"};
    cout << completeString(s);
    return 0;
}