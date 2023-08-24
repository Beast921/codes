#include<iostream>
#include<vector>
using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode{
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode *getNode(){
    TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false;
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
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

bool search(TrieNode *root, string key){
    TrieNode *pCrawl = root;
    for(int i=0;i<key.length();++i){
        int index = key[i] - 'a';
        if(!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return pCrawl->isEndOfWord;
}

bool wordBreak(TrieNode* root, string s){
    if(!s.length())
        return true;
    for(int i=1;i<=s.length();++i)
        if(search(root, s.substr(0,i)) && wordBreak(root, s.substr(i)))
            return true;
    return false;
}

int main(){
    vector<string> dict = {"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango"};
    string s = "ilikesamsung";
    
    TrieNode* root = getNode();
    for(auto s: dict)
        insert(root, s);

    if(wordBreak(root, s))
        cout<<"Yes";
    else
        cout<<"No";
    
    return 0;
}