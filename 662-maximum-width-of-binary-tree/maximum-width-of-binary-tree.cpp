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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        long long maxWidth = 0;

        // Queue stores: (node, index)
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int levelSize = q.size();
            long long minIndex = q.front().second; // normalize indices

            long long first = 0;
            long long last = 0;

            for (int i = 0; i < levelSize; i++) {
                auto current = q.front();
                q.pop();

                TreeNode* node = current.first;
                long long index = current.second - minIndex;

                if (i == 0) first = index;
                if (i == levelSize - 1) last = index;

                if (node->left) {
                    q.push({node->left, 2 * index + 1});
                }

                if (node->right) {
                    q.push({node->right, 2 * index + 2});
                }
            }

            maxWidth = max(maxWidth, last - first + 1);
        }

        return (int)maxWidth;
    }
};
