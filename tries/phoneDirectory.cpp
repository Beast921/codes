#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    struct TrieNode* child[26];
    bool isEnd;
    vector<int> idx;
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        isEnd=false;
    }
};

class Solution{
public:
    
    void insert(TrieNode* root,string word,int i){
        TrieNode* curr = root;
        for(auto c: word){
            int p=c-'a';
            if(curr->child[p]==NULL){
                curr->child[p]=new TrieNode();
            }
            curr=curr->child[p];
            curr->idx.push_back(i);
        }
        curr->isEnd = true;
    }
    
    void helper(TrieNode* root,string temp,vector<vector<string>>&ans,string contact[]){
        TrieNode* curr=root;
        for(auto c: temp){
            int ch=c-'a';
            if(curr->child[ch]==NULL){
                ans.push_back({"0"});
                return;
            }
            curr=curr->child[ch];
        }
        set<string>t;
        for(auto i: curr->idx){
            t.insert(contact[i]);
        }
        if(t.size()==0){
            ans.push_back({"0"});
        }
        else{
            vector<string>te;
            for(auto i: t){
                te.push_back(i);
            }
            ans.push_back(te);
        }
    }
    
    vector<vector<string>> displayContacts(int n, string contact[], string s){
        TrieNode* root = new TrieNode();
        for(int i=0;i<n;i++){
            insert(root,contact[i],i);
        }
        vector<vector<string>>ans;
        string temp="";
        for(int i=0;i<s.length();i++){
            temp+=s[i];
            helper(root,temp,ans,contact);
        }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}