#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<vector<TreeNode*>>> dp;

vector<TreeNode*> generate(int st, int en) {
    if(st > en)
        return {NULL};
    if(dp[st][en].size() > 0)
        return dp[st][en];
    vector<TreeNode*> res;
    for(int i=st;i<=en;++i) {
        vector<TreeNode*> left = generate(st, i-1);
        vector<TreeNode*> right = generate(i+1, en);
        for(auto l: left)
            for(auto r: right) {
                TreeNode *rt = new TreeNode(i);
                rt->left = l;
                rt->right = r;
                res.push_back(rt);
            }
    }
    return dp[st][en] = res;
}

vector<TreeNode*> generateTrees(int n) {
    dp.resize(n+1, vector<vector<TreeNode*>>(n+1, vector<TreeNode*>()));
    return generate(1, n);
}

void printPreorder(struct TreeNode* node) {
	if (!node) {
		cout<<"null"<<" ";
        return;
    }
	cout << node->val << " ";
	printPreorder(node->left);
	printPreorder(node->right);
}

int main() {
    int n = 3;
    vector<TreeNode*> ans = generateTrees(n);
    for(auto rt: ans) {
        printPreorder(rt);
        cout<<'\n';
    }
    return 0;
}