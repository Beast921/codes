#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int x) {
    Node* node = new Node;
    node->data = x;
    node->left = node->right = NULL;
}

void printLevelOrder(Node* root) {
    if(!root)   return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        cout<<q.front()->data<<" ";
        if(q.front()->left)
            q.push(q.front()->left);
        if(q.front()->right)
            q.push(q.front()->right);
        q.pop();
    }
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}