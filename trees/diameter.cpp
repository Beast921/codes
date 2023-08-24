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

pair<int, int> dfs(TreeNode *root) {
    if(!root) return {0, 0};
    pair<int, int> p1 = dfs(root->left), p2 = dfs(root->right);
    int d = p1.second + p2.second;
    int h = max(p1.second, p2.second);
    d = max(d, max(p1.first, p2.first));
    return {d, h+1};
}

int diameterOfBinaryTree(TreeNode* root) {
    pair<int, int> p = dfs(root);
    return p.first;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout<<diameterOfBinaryTree(root);
    return 0;
}