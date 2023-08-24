#include<iostream>
using namespace std;

int main() {
    int arr[] = { 2, 3, 4, 10, 40 }, x = 2, n = sizeof(arr)/sizeof(arr[0]), ans = -1;
    for(int i=0;i<n;++i)
        if(arr[i] == x){
            ans = i;
            break;
        }
    cout<<ans;
    return 0;
}