#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int x) {
    Node *node = new Node;
    node->data = x;
    node->left = node->right  = NULL;
}

void diagonalUtil(Node *root, int d, map<int, vector<int>>& diag) {
    if(!root)   return;
    diag[d].push_back(root->data);
    diagonalUtil(root->left, d+1, diag);
    diagonalUtil(root->right, d, diag);
}

void diagonalPrint(Node *root) {
    map<int, vector<int>> diag;
    diagonalUtil(root, 0, diag);
    for(auto it: diag){
        for(int i: it.second)
            cout<<i<<" ";
        cout<<"\n";
    }
}

int main()
{
    // Node* root = newNode(8);
    // root->left = newNode(3);
    // root->right = newNode(10);
    // root->left->left = newNode(1);
    // root->left->right = newNode(6);
    // root->right->right = newNode(14);
    // root->right->right->left = newNode(13);
    // root->left->right->left = newNode(4);
    // root->left->right->right = newNode(7);
 
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(9);
    root->left->right = newNode(6);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->right = newNode(7);
    root->right->left->left = newNode(12);
    root->left->right->left = newNode(11);
    root->left->left->right = newNode(10);

    diagonalPrint(root);

    return 0;
}