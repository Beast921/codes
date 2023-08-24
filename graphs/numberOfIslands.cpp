#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
    if(i<0 || j<0 || i>=m || j>=n)
        return;
    if(grid[i][j] == '0')
        return;
    grid[i][j] = '0';
    dfs(grid, i-1, j, m, n);
    dfs(grid, i, j+1, m, n);
    dfs(grid, i+1, j, m, n);
    dfs(grid, i, j-1, m, n);
}

int numIslands(vector<vector<char>>& grid) {
    int isl = 0;
    for(int i=0;i<grid.size();++i)
        for(int j=0;j<grid[i].size();++j)
            if(grid[i][j] == '1') {
                dfs(grid, i, j, grid.size(), grid[i].size());
                ++isl;
            }
    return isl;
}

int main() {
    vector<vector<char>> grid = {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};
    cout << numIslands(grid);
    return 0;
}