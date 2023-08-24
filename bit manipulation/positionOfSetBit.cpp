#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPosition(int n) {
        if(n && (n & (n-1)) == 0){
            int i=0;
            while(n){
                i++;
                n >>= 1;
            }
            return i;
        } else {
            return -1;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}