#include<iostream>
#include<vector>
using namespace std;

int compress(vector<char>& chars) {
    int ct = 1, i = 1;
    while(i<chars.size()) {
        if(chars[i-1] == chars[i]) {
            ct++;
            chars.erase(chars.begin()+i);
        } else {
            if(ct > 1) {
                int j=i;
                while(ct) {
                    chars.insert(chars.begin()+j, '0'+ct%10);
                    ct /= 10;
                    ++i;
                }
            }
            ct = 1;
            ++i;
        }
    }
    if(ct > 1)
        while(ct) {
            chars.insert(chars.begin()+i, '0'+ct%10);
            ct /= 10;
        }
    return chars.size();
}

int main() {
    vector<char> chars = {'a','a','b','b','c','c','c'};
    cout<<compress(chars);
    return 0;
}