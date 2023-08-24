#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return NULL;
    if(root == p || root == q) return root;
    TreeNode *a = lowestCommonAncestor(root->left, p, q);
    TreeNode *b = lowestCommonAncestor(root->right, p, q);
    if((a==p || b==p) && (a==q || b==q)) return root;
    if(a) return a;
    return b;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    TreeNode *p = root->left->left = new TreeNode(4);
    TreeNode *q = root->left->right = new TreeNode(5);
    TreeNode *t = lowestCommonAncestor(root, p, q);
    if(t) cout<<t->val;
    else cout<<"NULL";
    return 0;
}