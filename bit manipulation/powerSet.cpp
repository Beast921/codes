#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for(int i=0;i<(1<<nums.size());++i){
            vector<int> s;
            for(int j=0;j<nums.size();++j){
                if(i & (1<<j))
                    s.push_back(nums[j]);
            }
            res.push_back(s);
        }
        return res;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int> v;
        int n;
		cin >> n;
        while(n--){
            int x;
            cin>>x;
            v.push_back(x);
        }
		Solution ob;
		vector<vector<int>> res = ob.subsets(v);
        cout << "[";
		for(int i=0;i<res.size();++i){
            cout<<"[";
            for(int j=0;j<res[i].size();++j){
                cout<<res[i][j];
                if(j!=res[i].size()-1)
                    cout<<", ";
            }
            cout<<"]";
            if(i!=res.size()-1)
                cout<<", ";
        }
		cout << "]\n";

	}
	return 0;
}