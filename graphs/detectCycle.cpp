#include<iostream>
#include<vector>
using namespace std;

bool dfs(int n, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& checkd) {
    if(checkd[n])
        return true;
    if(vis[n])
        return false;
    vis[n] = true;
    for(int i: adj[n])
        if(!dfs(i, adj, vis, checkd))
            return false;
    checkd[n] = true;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses, vector<int>());
    vector<bool> vis, checkd(numCourses, false);
    for(auto preq: prerequisites)
        adj[preq[0]].push_back(preq[1]);
    for(int i=0;i<numCourses;++i){
        vis.resize(numCourses, false);
        if(!dfs(i, adj, vis, checkd))
            return false;
        vis.clear();
    }
    return true;
}

int main() {
    int numCourses = 2;
    vector<vector<int>> preq = {{1,0},{0,1}};
    if(canFinish(numCourses, preq))
        cout<<"Can finish";
    else
        cout<<"Can not finish";
    return 0;
}