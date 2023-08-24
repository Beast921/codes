#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isSafe(int n, int r, int c, vector<string>& board) {
    for(int i=0;i<r;++i)
        if(board[i][c] == 'Q')
            return false;
    for(int i=r-1,j=c-1;i>=0&&j>=0;--i,--j)
        if(board[i][j] == 'Q')
            return false;
    for(int i=r-1,j=c+1;i>=0&&j<n;--i,++j)
        if(board[i][j] == 'Q')
            return false;
    return true;
}

void solve(int n, int r, vector<string>& board, int& ans) {
    if(r == n) {
        ans++;
        return;
    }
    string s = "";
    for(int i=0;i<n;++i)
        s += '.';
    for(int i=0;i<n;++i)
        if(isSafe(n, r, i, board)) {
            s[i] = 'Q';
            board.push_back(s);
            solve(n, r+1, board, ans);
            board.pop_back();
            s[i] = '.';
        }
}

int totalNQueens(int n){
    vector<string> board;
    int ans = 0;
    solve(n, 0, board, ans);
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<totalNQueens(n);
    return 0;
}