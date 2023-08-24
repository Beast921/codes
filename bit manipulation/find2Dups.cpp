#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int getBit(int n, int i){
        return n & 1<<i;
    }
    vector<int> singleNumber(vector<int> nums){
        int xors = 0;
        for(int n: nums)
            xors ^= n;
        int pos = 0, set = 0, temp = xors, newxor = 0;
        while(set != 1){
            set = temp & 1;
            pos++;
            temp >>= 1;
        }
        for(int n: nums){
            if(getBit(n, pos-1))
                newxor ^= n;
        }
        vector<int> v = {newxor, newxor^xors};
        sort(v.begin(), v.end());
        return v;   
    }
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}