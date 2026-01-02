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
    void flatten(TreeNode* root) {
        flattenTree(root);
    }

private:
    TreeNode* prev = nullptr;

    void flattenTree(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        // Process right subtree first
        flattenTree(node->right);

        // Process left subtree
        flattenTree(node->left);

        // Rewire pointers
        node->right = prev;
        node->left = nullptr;

        // Move prev pointer
        prev = node;
    }
};

