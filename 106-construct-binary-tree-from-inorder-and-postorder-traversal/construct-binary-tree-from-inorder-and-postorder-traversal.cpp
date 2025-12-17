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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndex;

        // Store index of each value in inorder traversal
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        int postIndex = postorder.size() - 1;
        return build(inorder, postorder, postIndex, 0, inorder.size() - 1, inorderIndex);
    }
private:
    TreeNode* build(vector<int>& inorder,
                    vector<int>& postorder,
                    int& postIndex,
                    int inLeft,
                    int inRight,
                    unordered_map<int, int>& inorderIndex) {
        // Base case
        if (inLeft > inRight) {
            return nullptr;
        }
        // Root value from postorder
        int rootValue = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootValue);
        // Find root in inorder
        int mid = inorderIndex[rootValue];
        // IMPORTANT:
        // Build right subtree first, then left subtree
        root->right = build(inorder, postorder, postIndex, mid + 1, inRight, inorderIndex);
        root->left = build(inorder, postorder, postIndex, inLeft, mid - 1, inorderIndex);
        return root;
    }
};
