#include<iostream>
using namespace std;

bool isSubsequence(string s, string t) {
    if(!s.length()) return true;
    if(s.length() > t.length()) return false;
    for(int i=0,j=0;i<t.length();++i) {
        if(t[i] == s[j]) ++j;
        if(j == s.length()) return true;
    }
    return false;
}

int main() {
    string s="aeg", t="abcdefgh";
    if(isSubsequence(s, t))
        cout<<"Is subsequence";
    else
        cout<<"Is not subsequence";
    return 0;
}