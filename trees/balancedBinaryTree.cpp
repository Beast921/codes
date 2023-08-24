// to check if height-balanced
// height of both subtrees dont differ by more than 1

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

pair<bool, int> dfs(TreeNode *root) {
    if(!root) return {true, 0};
    auto l = dfs(root->left);
    if(!l.first) return {false, 0};
    auto r = dfs(root->right);
    if(!r.first) return {false, 0};
    if(abs(l.second-r.second)>1) return {false, 0};
    int d = max(l.second,r.second) + 1;
    return {true, d};
}

bool isBalanced(TreeNode* root) {
    return dfs(root).first;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    if(isBalanced(root)) cout<<"Balanced";
    else cout<<"Unbalanced";
    return 0;
}