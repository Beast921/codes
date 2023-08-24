#include<iostream>
using namespace std;

int binarySearch(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while(l<=r) {
        int m = (l+r)/2;
        if(a[m] == x)
            return m;
        else if(a[m] < x)
            l = m+1;
        else
            r = m-1;
    }
    return -1;
}

int main() {
    int a[7] = {4,2,7,9,3,6,8}, n = sizeof(a)/sizeof(*a);
    cout<<binarySearch(a, n, 9);
    return 0;
}