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
        vector<int> inorder(TreeNode* root){
        // calcuting using recursive method
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* temp = root;
        while(!st.empty() || temp!=nullptr){
            TreeNode* curr = temp;
            while(temp){
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            temp = temp->right;
        }
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ino = inorder(root);
        int n = ino.size();
        return ino[k-1];
        
        
    }
};