#include<iostream>
using namespace std;

string mergeAlternately(string word1, string word2) {
    int i=0, j=0;
    string s;
    bool b=true;
    while(i<word1.length() && j<word2.length()) {
        if(b)
            s += word1[i++];
        else
            s += word2[j++];
        b = !b;
    }
    s += word1.substr(i);
    s += word2.substr(j);
    return s;
}

int main() {
    string word1 = "abc", word2 = "pqrstu";
    cout<<mergeAlternately(word1, word2);
    return 0;
}