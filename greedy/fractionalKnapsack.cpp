#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    static bool comp(Item a, Item b) {
        return (double)a.value/(double)a.weight > (double)b.value/(double)b.weight;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, comp);
        int i=0;
        double ans=0.0;
        while(i<n && W>0){
            if(arr[i].weight<=W) {
                ans += arr[i].value;
                W -= arr[i].weight;
                i++;
            } else {
                ans += W * ((double)arr[i].value/(double)arr[i].weight);
                W = 0;
            }
        }
        return ans;
    }
        
};


int main() {
	int t;
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}