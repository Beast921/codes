#include<iostream>
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

bool isEmpty(TrieNode *root){
    for(int i=0;i<ALPHABET_SIZE;++i)
        if(root->children[i])
            return false;
        return true;
}

TrieNode* remove(TrieNode* root, string key, int depth = 0){
    if(!root)
        return NULL;
        
    if(depth == key.size()){

        // This node is no more end of word after
        // removal of given key
        if(root->isEndOfWord)
            root->isEndOfWord = false;

        // If given is not prefix of any other word
        if(isEmpty(root)){
            delete(root);
            root = NULL;
        }
        return root;
    }

    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth+1);

    // If root does not have any child (its only child got
    // deleted), and it is not end of another word.
    if(isEmpty(root) && root->isEndOfWord == false){
        delete(root);
        root = NULL;
    }
    
    return root;
}

void display(TrieNode* root, string str){
    if(root->isEndOfWord)
        cout<<str<<endl;

    for(int i=0;i<ALPHABET_SIZE;++i)
        if(root->children[i]){
            char c = i+'a';
            display(root->children[i], str+c);
        }
}

int main(){
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int n = sizeof(keys)/sizeof(keys[0]);
    TrieNode *root = getNode();
    for(int i=0;i<n;++i)
        insert(root, keys[i]);
    
    string search_keys[] = {"the", "thaw", "these", "their"};
    n = sizeof(search_keys)/sizeof(search_keys[0]);
    for(int i=0;i<n;++i){
        cout<<search_keys[i]<<" --- ";
        if(search(root, search_keys[i]))
            cout<<"Present in trie\n";
        else
            cout<<"Not present in trie\n";
    }
    remove(root, "the");
    if(search(root, "the"))
            cout<<"Present in trie\n";
        else
            cout<<"Not present in trie\n";
    display(root, "");

    return 0;
}