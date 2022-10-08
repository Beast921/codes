#include<iostream>
#include<vector>
using namespace std;

bool canConstruct(string s, string t) {
    if(s.length()!=t.length()) return false;
    bool b=true;
    vector<int> c1(26,0),c2(26,0);
    for(char x:s)
        c1[x-'a']++;
    for(char x:t)
        c2[x-'a']++;
    for(char x:s)
        if(c1[x-'a']!=c2[x-'a'])
            b=false;
    return b;
}

int main(){
    cout<<canConstruct("ab","aab");
}