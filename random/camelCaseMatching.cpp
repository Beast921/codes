//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include<string.h>
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string> v;
        for(string s: Dictionary){
            string pat="";
            for(char c: s)
                if(c>=65 && c<=90)
                    pat+=c;
            bool b = false;
            int i = 0;
            while(pat.length()>=Pattern.length() && i<Pattern.length()){
                if(pat[i]==Pattern[i])
                    b=true;
                else{
                    b=false;
                    break;
                }
                i++;
            }
            if(b)
                v.push_back(s);
        }
        sort(v.begin(), v.end());
        if(v.empty())
            return {"-1"};
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends