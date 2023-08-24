#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> res;
		    int n = s.length();
		    for(int i=0;i<(1<<n);++i){
		        string t = "";
		        for(int j=0;j<n;++j)
		            if(i & 1<<j)
		                t += s[j];
		        if(t!="")
		            res.push_back(t);
		    }
		    sort(res.begin(), res.end());
		    return res;
		}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}