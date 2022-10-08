#include<iostream>
#include<vector>
#include<ctype.h>
using namespace std;

bool isNice(string s){
    vector upper(26,0),lower(26,0);
    for(char c:s){
        if(isupper(c))
            upper[c-'A']++;
        else
            lower[c-'a']++;
    }
    for(int i=0;i<26;++i)
        if(upper[i]>0 && lower[i]==0 || upper[i]==0 && lower[i]>0)
            return false;
    return true;
}

string longestNiceSubstring(string s) {
    string max="";
    for(int i=0;i<s.length();++i){
        string t="";
        t+=s[i];
        for(int j=i+1;j<s.length();++j){
            t+=s[j];
            if(isNice(t) && t.length()>max.length())
                max=t;
        }
    }
    return max;
}

int main(){
    cout<<longestNiceSubstring("a");
}