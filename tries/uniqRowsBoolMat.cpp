//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

class TrieNode {
    public:
    TrieNode* children[2];
    TrieNode() {
        for(int i=0;i<2;i++)
            children[i] = NULL;
    }
};

class Trie {
    private:
    TrieNode * root;
    
    public:
    Trie() {
        root = new TrieNode();
    }
    
    int insert(vector<int> &a) {
        int l = a.size();
        TrieNode * cur = root;
        
        int flag = 0;
        for(int i=0;i<l;i++) {
            if(cur->children[a[i]]==NULL) {
                cur->children[a[i]] = new TrieNode();
                flag++;
            } 
            cur = cur->children[a[i]];
        }
        return flag;
    }
};

class Solution
{
    public:
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col){
        vector<vector<int>> given(row, vector<int>(col, 0));
        vector<vector<int>> ans;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                given[i][j] = M[i][j];
            }
        }
        
        Trie* obj = new Trie();
        
        for(auto it : given) {
            if(obj->insert(it)>0) {
                ans.push_back(it);
            }
        }
        return ans;
    }
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}