#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


void countPairs(unordered_map<int, vector<pair<int, int>>>& adj, vector<int>& val, int& count, int n, int dist) {
    if(!adj.count(n)) return;
    for(auto i: adj[n]) {
        if(dist+i.second <= val[i.first-1]) count++;
        countPairs(adj, val, count, i.first, dist+i.second);
    }
}

void dfs(unordered_map<int, vector<pair<int, int>>>& adj, vector<int>& val, int& count, int n) {
    if(!adj.count(n)) return;
    countPairs(adj, val, count, n, 0);
    for(auto i: adj[n])
        dfs(adj, val, count, i.first);
}

int countCompatiblePairs(int n, vector<int>& from, vector<int>& to, vector<int>& weight, vector<int>& val) {
    int count = 0;
    unordered_map<int, vector<pair<int, int>>> adj;
    for(int i=0;i<from.size();++i)
        adj[from[i]].push_back({to[i], weight[i]});
    dfs(adj, val, count, 1);
    return count;
}

int main() {
    int n = 6;
    vector<int> from = {1,6,6,1,2};
    vector<int> to = {6,5,2,4,3};
    vector<int> weight = {4,1,3,3,1};
    vector<int> val = {2,2,8,3,5,4};
    cout<<countCompatiblePairs(n, from, to, weight, val);
    return 0;
}