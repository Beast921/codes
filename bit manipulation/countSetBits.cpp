#include<iostream>
using namespace std;

int main(){
    int n, c=0;
    cin>>n;
    while(n){
        if(n & 1) c++;
        n = n >> 1;
    }
    cout<<c;
    return 0;
}