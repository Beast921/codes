#include<bits/stdc++.h>
using namespace std; 

struct Job { 
    int id;
    int dead;
    int profit;
}; 

class Solution {
    public:
    static  bool cmp(Job &a , Job &b ){
        return (a.profit > b.profit); 
    }
    
    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr, arr+n, cmp);
        vector<bool> slot(n+1, false);
        int cnt=0, prf=0;
        for(int i=0;i<n;++i) {
            for(int j=arr[i].dead;j>0;--j)
                if(!slot[j]) {
                    cnt++;
                    prf += arr[i].profit;
                    slot[j] = true;
                    break;
                }
        }
        return {cnt, prf};
    }
};

int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        Job arr[n];
        
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}
