#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    vector<int> leaf1;
    vector<int> leaf2;

public:
    void dfs(TreeNode* root, vector<int>& leaf) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            leaf.push_back(root->val);
            return;
        }
        dfs(root->left, leaf);
        dfs(root->right, leaf);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, leaf1);
        dfs(root2, leaf2);
        if (leaf1.size() != leaf2.size())
            return false;
        int size = leaf1.size();
        for (int i = 0; i < size; i++) {
            if (leaf1[i] != leaf2[i])
                return false;
        }
        return true;
    }
};
