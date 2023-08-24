#include<iostream>
#include<cmath>
using namespace std;

int NthRoot(int n, int m) {
  if(m==1 || n==1)
    return m;
  int l=2, r=m-1;
  while(l<=r) {
    int mid = (l+r)/2;
    if(pow(mid, n) == m)
      return mid;
    else if(pow(mid, n)<m)
      l = mid+1;
    else
      r = mid-1;
  }
  return -1;
}

int main() {
    int n=3, m=64;
    cout<<NthRoot(n, m);
    return 0;
}