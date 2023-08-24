#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode{
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    vector<int> items;
};

TrieNode *getNode(){
    TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false;
    pNode->items = {};
    for(int i=0;i<ALPHABET_SIZE;++i)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(TrieNode *root, string key, int i){
    TrieNode *pCrawl = root;
    for(int i=0;i<key.length();++i){
        int index = key[i] - 'a';
        if(!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
    pCrawl->items.push_back(i);
}

void printAnagrams(TrieNode *root, vector<string>& dict){
    if(root->isEndOfWord){
        for(int i: root->items)
            cout<<dict[i]<<" ";
        cout<<endl;
    }
    for(int i=0;i<ALPHABET_SIZE;++i){
        if(root->children[i])
            printAnagrams(root->children[i], dict);
    }
}

int main(){
    vector<string> dict = {"cat", "dog", "tac", "god", "act"};
    
    TrieNode* root = getNode();
    for(int i=0;i<dict.size();++i){
        string s = dict[i];
        sort(s.begin(), s.end());
        insert(root, s, i);
    }
    printAnagrams(root, dict);
    return 0;
}