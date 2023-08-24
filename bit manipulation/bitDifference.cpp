#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countBitsFlip(int a, int b){
        int c = 0;
        while(a!=b){
            if((a & 1) != (b & 1))
                c++;
            a >>= 1;
            b >>= 1;
        }
        return c;
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int a, b;
		cin>>a>>b;
        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}