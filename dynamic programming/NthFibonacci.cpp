#include<iostream>
using namespace std;

int fib(int n) {
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    int a=0, b=1, ans;
    for(int i=2;i<=n;++i){
        ans = a+b;
        a = b;
        b = ans;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}