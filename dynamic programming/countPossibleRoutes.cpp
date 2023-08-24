#include<iostream>
#include<vector>
using namespace std;

int mod = 1e9+7;

int solveMem(vector<int>& locations, int start, int finish, int fuel, vector<vector<int>>& dp) {
    if(fuel<0)
        return 0;
    if(dp[start][fuel]==-1){
        int ans = 0;
        if(start==finish)
            ans = 1;
        for(int i=0;i<locations.size();++i){
            if(i!=start)
                ans = (ans + solveMem(locations, i, finish, fuel-abs(locations[start]-locations[i]), dp)) % mod;
        }
        dp[start][fuel] = ans;
    }
    return dp[start][fuel];
}

int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    vector<vector<int>> dp(locations.size()+1, vector<int>(fuel+1, -1));
    return solveMem(locations, start, finish, fuel, dp);
    
    // vector<vector<int>> dp(locations.size()+1, vector<int>(fuel+1, 0));
    // for(int i=0;i<=fuel;++i)
    //     dp[finish][i]=1;
    // for(int i=0;i<=fuel;++i)
    //     for(int j=0;j<locations.size();++j)
    //         for(int k=0;k<locations.size();++k)
    //             if(k!=j && i>=abs(locations[k]-locations[j]))
    //                 dp[j][i] = (dp[j][i] + dp[k][i-abs(locations[k]-locations[j])]) % mod;
    // return dp[start][fuel];
}

int main() {
    vector<int> v = {2,3,6,8,4};
    int start = 1, finish = 3, fuel = 5;
    cout<<countRoutes(v, start, finish, fuel);
    return 0;
}