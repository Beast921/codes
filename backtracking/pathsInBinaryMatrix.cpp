#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> v;
    vector<pair<char, pair<int, int>>> dir = {{'U', {-1,0}}, {'R', {0,1}}, {'D', {1,0}}, {'L', {0,-1}}};

    void paths(vector<vector<int>> &m, int n, vector<bool> vis, string s, int i, int j){
        if(i==n-1 && j==n-1){
            v.push_back(s);
        }
        vis[i*n+j] = true;
        for(auto p: dir){
            int a = i+p.second.first, b = j+p.second.second;
            if(a>=0 && b<=n-1 && a<=n-1 && b>=0 && m[a][b] && !vis[a*n+b])
                paths(m, n, vis, s+p.first, a, b);
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(!m[0][0] || !m[n-1][n-1])
            return {"-1"};
        vector<bool> vis(n*n, false);
        paths(m, n, vis, "", 0, 0);
        if(v.empty())
            v.push_back("-1");
        else
            sort(v.begin(), v.end());
        return v;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}