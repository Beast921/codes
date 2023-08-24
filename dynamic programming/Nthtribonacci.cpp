#include<iostream>
using namespace std;

int tribonacci(int n) {
    if(n==0)
        return 0;
    if(n<=2)
        return 1;
    int a=0, b=1, c=1;
    for(int i=3;i<=n;++i){
        int ans = a+b+c;
        a = b;
        b = c;
        c = ans;
    }
    return c;
}

int main() {
    cout<<tribonacci(7);
    return 0;
}