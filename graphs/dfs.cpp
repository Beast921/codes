#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int n, vector<int> adj[], vector<bool>& vis, vector<int>& res) {
        vis[n] = true;
        res.push_back(n);
        for(int i: adj[n])
            if(!vis[i])
                dfs(i, adj, vis, res);
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<int> res;
        dfs(0, adj, vis, res);
        return res;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}