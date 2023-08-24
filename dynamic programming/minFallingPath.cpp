#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=n-2;i>=0;--i){
        for(int j=0;j<n;++j){
            int a,b,c;
            a=b=c=INT_MAX;
            if(j!=0)
                a = matrix[i+1][j-1];
            b = matrix[i+1][j];
            if(j!=n-1)
                c = matrix[i+1][j+1];
            matrix[i][j] += min(a, min(b, c));
        }
    }
    int ans = INT_MAX;
    for(int i=0;i<n;++i)
        ans = min(ans, matrix[0][i]);
    return ans;
}

int main() {
    vector<vector<int>> v({{2,1,3},{6,5,4},{7,8,9}});
    cout<<minFallingPathSum(v);
    return 0;
}