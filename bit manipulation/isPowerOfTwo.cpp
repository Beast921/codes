#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isPowerofTwo(long long n){
        return n && (n & (n-1)) == 0;
    }
};

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        long long n; 
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}