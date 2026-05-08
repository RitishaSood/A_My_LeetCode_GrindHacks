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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;
        // Store index of each value in inorder traversal
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        int preIndex = 0;
        return build(preorder, inorder, preIndex, 0, inorder.size() - 1, inorderIndex);
    }
private:
    TreeNode* build(vector<int>& preorder,
                    vector<int>& inorder,
                    int& preIndex,
                    int inLeft,
                    int inRight,
                    unordered_map<int, int>& inorderIndex) {
        // Base case
        if (inLeft > inRight) {
            return nullptr;
        }
        // Current root value from preorder
        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);
        // Split inorder array
        int mid = inorderIndex[rootValue];
        // Build left and right subtrees
        root->left = build(preorder, inorder, preIndex, inLeft, mid - 1, inorderIndex);
        root->right = build(preorder, inorder, preIndex, mid + 1, inRight, inorderIndex);
        return root;
    }
};
