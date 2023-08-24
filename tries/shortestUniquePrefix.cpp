#include<iostream>
#include<vector>
using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode{
    TrieNode *children[ALPHABET_SIZE];
    int freq;
};

TrieNode *getNode(){
    TrieNode *pNode = new TrieNode;
    pNode->freq = 1;
    for(int i=0;i<ALPHABET_SIZE;++i)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(TrieNode *root, string key){
    TrieNode *pCrawl = root;
    for(int i=0;i<key.length();++i){
        int index = key[i] - 'a';
        if(!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        else
            (pCrawl->children[index]->freq)++;
        pCrawl = pCrawl->children[index];
    }
}

void uniquePrefixes(TrieNode* root, string s, vector<string>& v){
    if(!root)
        return;
    if(root->freq == 1){
        s += '\0';
        v.push_back(s);
        return;
    }
    for(int i=0;i<ALPHABET_SIZE;++i)
        if(root->children[i]){
            char c = i+'a';
            uniquePrefixes(root->children[i], s+c, v);
        }
}

int main(){
    string keys[] = {"geeksgeeks", "geeksquiz", "geeksforgeeks"};
    int n = sizeof(keys)/sizeof(keys[0]);
    TrieNode *root = getNode();
    root->freq = 0;
    for(int i=0;i<n;++i)
        insert(root, keys[i]);
    vector<string> prefs;
    uniquePrefixes(root, "", prefs);
    for(auto s: prefs)
        cout<<s<<" ";

    return 0;
}