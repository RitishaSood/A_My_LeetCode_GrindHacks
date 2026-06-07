/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        queue<TreeNode*> q;

        // Edge case
        if(root == NULL)
            return ans;

        // Start traversal
        q.push(root);

        while(!q.empty()) {

            // Number of nodes in current level
            int size = q.size();

            vector<int> level;

            // Traverse current level
            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Store node value
                level.push_back(node->val);

                // Push left child
                if(node->left)
                    q.push(node->left);

                // Push right child
                if(node->right)
                    q.push(node->right);
            }

            // Store current level
            ans.push_back(level);
        }

        return ans;
    }
};