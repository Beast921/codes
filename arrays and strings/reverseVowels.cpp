#include<iostream>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

string reverseVowels(string s) {
    int i=0, j=s.length();
    while(i < j) {
        if(isVowel(s[i]) && isVowel(s[j]))
            swap(s[i++], s[j--]);
        else {
            if(!isVowel(s[i]))
                ++i;
            if(!isVowel(s[j]))
                --j;
        }
    }
    return s;
}

int main() {
    string s = "idklmao";
    cout<<reverseVowels(s);
    return 0;
}