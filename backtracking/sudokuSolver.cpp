#include <bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  

class Solution {
    public:
    bool isSafe(int grid[N][N], int a, int b, int x){
        for(int i=0;i<9;++i)
            if(grid[a][i]==x)
                return false;
        for(int i=0;i<9;++i)
            if(grid[i][b]==x)
                return false;
        int p=a/3, q=b/3;
        for(int i=0;i<3;++i)
            for(int j=0;j<3;++j)
                if(grid[p*3+i][q*3+j]==x)
                    return false;
        return true;
    }

    bool SolveSudoku(int grid[N][N], int a=0, int b=0)  { 
        if(a==N){
            return true;
        }
        bool res = false;
        if(grid[a][b]){
            a = (b==N-1) ? a+1 : a;
            res = SolveSudoku(grid, a, (b+1)%N);
        } else {
            int c = (b==N-1) ? a+1 : a;
            for(int i=1;i<=9;++i){
                if(isSafe(grid, a, b, i)){
                    grid[a][b] = i;
                    if(SolveSudoku(grid, c, (b+1)%N))
                        return true;
                    else
                        grid[a][b] = 0;
                }
            }
        }
        return res;
    }
    
    void printGrid (int grid[N][N]) {
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}