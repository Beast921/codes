#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isSafe(bool graph[101][101], int n, int i, int color[], int c) {
        for(int j=0;j<n;++j)
            if(graph[i][j] && color[j]==c)
                return false;
        return true;
    }
    
    bool helper(int i, bool graph[101][101], int m, int n, int color[]) {
        if(i==n)
            return true;
        for(int c=1;c<=m;++c){
            if(isSafe(graph, n, i, color, c)){
                color[i] = c;
                if(helper(i+1, graph, m, n, color))
                    return true;
                color[i] = 0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n];
        return helper(0, graph, m, n, color);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}