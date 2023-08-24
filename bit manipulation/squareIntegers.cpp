#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long square(long long n) {
        n = abs(n);
        int a=0, t=n, p=0;
        while(t){
            if(t & 1)
                a += (n << p);
            t >>= 1;
            p++;
        }
        return a;
    }
};

int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a;
		cin >> a;
		
		Solution ob;
		cout << ob.square(a) << "\n";
	}

	return 0;
}