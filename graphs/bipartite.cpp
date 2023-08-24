#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool checkBip(vector<vector<int>>& graph, map<int, bool>& bip, int n, bool b) {
    if(bip.count(n))
        return bip[n]==b;
    bip[n] = b;
    for(int i: graph[n])
        if(!checkBip(graph, bip, i, !b))
            return false;
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    map<int, bool> bip;
    for(int i=0;i<graph.size();++i)
        if(!bip.count(i) && !checkBip(graph, bip, i, true))
            return false;
    return true;
}

int main() {
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    if(isBipartite(graph))
        cout<<"True";
    else
        cout<<"False";
    return 0;
}