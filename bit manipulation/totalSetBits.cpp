#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countSetBits(int n){
        n++;
        int i=0,p=2,sbit=n/2;
        while(p<=n){
            sbit += n/p/2*p;
            if((n/p)%2)
                sbit += n%p;
            p <<= 1;
            i++;
        }
        return sbit;
    }
};

int main()
{
	 int t;
	 cin>>t;
	 while(t--) 
	 {
	       int n;
	       cin>>n;
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;
	  }
	  return 0;
}