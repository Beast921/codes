#include<iostream>
#include<algorithm>
using namespace std;

int findPlatform(int arr[], int dep[], int n) {
    sort(arr, arr+n);
    sort(dep, dep+n);
    int ans=1, j=0, i=1, plat=1;
    while(i<n && j<n) {
        if(arr[i] <= dep[j]) {
            i++;
            plat++;
        } else if(arr[i] > dep[j]) {
            j++;
            plat--;
        }
        ans = max(ans, plat);
    }
    return ans;
}

int main() {
    int n = 6;
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    cout<<findPlatform(arr, dep, n);
    return 0;
}