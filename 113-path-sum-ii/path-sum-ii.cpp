/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void dfs(TreeNode* node, int targetSum) {
        if (!node) return;
        path.push_back(node->val);
        targetSum -= node->val;
        // Check if it's a leaf node
        if (!node->left && !node->right && targetSum == 0) {
            result.push_back(path);
        }
        dfs(node->left,targetSum);
        dfs(node->right,targetSum);
        // Backtrack
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return result;
    }
};
