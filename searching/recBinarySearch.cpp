#include<iostream>
using namespace std;

int binarySearch(int a[], int l, int r, int x) {
    if(l>r)
        return -1;
    int m = (l+r)/2;
    if(a[m] == x)
        return m;
    if(a[m] < x)
        return binarySearch(a, m+1, r, x);
    return binarySearch(a, l, m-1, x);
}

int main() {
    int a[7] = {4,2,7,9,3,6,8}, n = sizeof(a)/sizeof(*a);
    cout<<binarySearch(a, 0, n-1, 9);
    return 0;
}