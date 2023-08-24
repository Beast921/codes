#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxLength(vector<string>& dict){
        int m = 0;
        for(string s: dict){
            int n = s.length();
            m = max(m, n);
        }
        return m;
    }
    
    void formSentence(vector<string>& res, int x, vector<string>& dict, int m, string s, string s1, string s2){
        if(x==s.length()){
            if(s1.length()==0){
                s2.pop_back();
                res.push_back(s2);
            } else
                return;
        }
        if(s1.length() == m)
            return;
        s1 += s[x];
        if(binary_search(dict.begin(), dict.end(), s1))
            formSentence(res, x+1, dict, m, s, "", s2+s1+" ");
        formSentence(res, x+1, dict, m, s, s1, s2);
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s){
        sort(dict.begin(), dict.end());
        int m = maxLength(dict);
        vector<string> res;
        formSentence(res, 0, dict, m, s, "", "");
        return res;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}