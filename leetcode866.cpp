#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<TreeNode*, int> heights;
    int depth = 0;
    TreeNode* ans = NULL;

public:
    int rec_height(TreeNode* root, int d) {
        if (root == NULL)
            return 0;
        if (d > depth)
            depth = d;

        int tmp = max(rec_height(root->left, d + 1), rec_height(root->right, d + 1)) + 1;
        heights[root] = tmp;
        return tmp;
    }

    bool balance(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)
            return true;
        if (root->left == NULL || root->right == NULL)
            return false;
        return heights[root->left] == heights[root->right];
    }

    void dfs(TreeNode* root, int d) {
        if (root == NULL)
            return;
        int height = heights[root];
        if (height + d != depth + 1)
            return;
        if (!balance(root)) {
            dfs(root->left, d + 1);
            dfs(root->right, d + 1);
            return;
        }
        ans = root;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        rec_height(root, 0);
        dfs(root, 0);
        return ans;
    }
};
