#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> v){
    for(int i=0;i<v.size()/2;++i){
        int t = v[i];
        v[i] = v[v.size()-1-i];
        v[v.size()-1-i] = t;
    }
    return v;
}

int main(){
    int n,x;
    cin>>n;
    vector<int> v;
    while(n--){
        cin>>x;
        v.push_back(x);
    }
    v = reverse(v);
    for(int i: v)
        cout<<i;
    cout<<endl;
}