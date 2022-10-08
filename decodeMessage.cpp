#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string decodeMessage(string key, string message) {
    vector<char> sub(26);
    string out;
    for(int i=0,j=0;i<26&&j<key.length();++j){
        if(!binary_search(sub.begin(),sub.end(),key[j])){
            sub[i]=key[j];
            i++;
        }
    }
    
    return out;
}

int main(){
    string key="the quick brown fox jumps over the lazy dog",msg="vkbs bs t suepuv";
    cout<<decodeMessage(key,msg);
}