#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isSafe(int i, int j, vector<vector<int>>& board){
    for(int a=0;a<i;++a){
        for(int b=0;b<board.size();++b){
            if(board[a][b] && (j==b || a+b==i+j || a-b==i-j))
                return false;
        }
    }
    return true;
}

void findPos(int i, vector<vector<int>>& board, vector<vector<int>>& res){
    if(i == board.size()){
        vector<int> v;
        for(auto b: board){
            for(int j=0;j<b.size();++j)
                if(b[j]==1)
                    v.push_back(j+1);
        }
        res.push_back(v);
    }
    for(int j=0;j<board.size();++j)
        if(isSafe(i, j, board)){
            board[i][j] = 1;
            findPos(i+1, board, res);
            board[i][j] = 0;
        }
}

vector<vector<int>> nQueen(int n){
    vector<vector<int>> board(n, vector<int>(n, 0)), res;
    findPos(0, board, res);
    if(!res.empty())
        sort(res.begin(), res.end());
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> res = nQueen(n);
    if(res.empty())
        cout<<"No solutions.";
    else
        for(auto v: res){
            cout<<'[';
            for(auto i: v){
                cout<<i<<' ';
            }
            cout<<"] ";
        }
    return 0;
}