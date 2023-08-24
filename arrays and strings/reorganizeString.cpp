#include<iostream>
#include<vector>
using namespace std;

string reorganizeString(string s) {
    vector<int> count(26, 0);
    for(char c: s)
        count[c-'a']++;
    int maxcount = 0, letter = 0;
    for(int i=0;i<count.size();++i)
        if(count[i] > maxcount) {
            maxcount = count[i];
            letter = i;
        }
    if(maxcount > (s.length()+1)/2)
        return "Cannot reorganize";
    string ans = s;
    int ind = 0;
    while(count[letter]) {
        ans[ind] = char(letter + 'a');
        ind += 2;
        count[letter]--;
    }
    for(int i=0;i<count.size();++i)
        while(count[i] > 0){
            if(ind >= s.length())
                ind = 1;
            ans[ind] = char(i + 'a');
            ind += 2;
            count[i]--;
        }
    return ans;
}

int main() {
    string s = "aab";
    cout<<reorganizeString(s);
    return 0;
}