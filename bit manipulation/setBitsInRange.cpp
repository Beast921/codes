#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int setAllRangeBits(int N , int L , int R) {
        while(L<=R){
            N = N | 1<<(L++ - 1);
        }
        return N;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        cin>>N>>L>>R;
        Solution ob;
        cout << ob.setAllRangeBits(N,L,R) << endl;
    }
    return 0;
}