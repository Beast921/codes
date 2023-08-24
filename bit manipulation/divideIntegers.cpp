#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) {
        int sign = 1;
        if((dividend>0 && divisor<0) || (dividend<0 && divisor>0))
            sign = -1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        int q=0,t=0;
        for(int i=31;i>=0;--i){
            if(t+(divisor<<i) <= dividend){
                t += divisor<<i;
                q = q | (1LL<<i);
            }
        }
        return sign*q;
    }
};

int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}