#include<iostream>
#include<algorithm>
using namespace std;

string gcdOfStrings(string str1, string str2) {
    if(str1+str2 != str2+str1) return "";
    return str1.substr(0, __gcd(str1.length(), str2.length()));
}

int main() {
    cout<<gcdOfStrings("ABABAB", "ABAB")<<'\n';
    cout<<gcdOfStrings("ABCABC", "ABC")<<'\n';
    cout<<gcdOfStrings("LMAO", "BRUH")<<'\n';
    return 0;
}