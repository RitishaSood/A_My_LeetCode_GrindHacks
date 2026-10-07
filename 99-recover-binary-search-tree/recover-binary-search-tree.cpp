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
private :
    void trackinorder(TreeNode* root, vector<int> &ino){
        if(root==nullptr){
            return;
        }
        trackinorder(root->left,ino);
        ino.push_back(root->val);
        trackinorder(root->right,ino);
    }
    void recoverinorder(TreeNode* root, vector<int> &ino, int& idx){
        if(root==nullptr){
            return;
        }
        recoverinorder(root->left,ino,idx);
        root->val = ino[idx++];
        recoverinorder(root->right,ino,idx);
    }
public:
    void recoverTree(TreeNode* root) {
       //your code goes here
       vector<int> ino;
       int idx = 0;
       trackinorder(root,ino);
       sort(ino.begin(),ino.end());
       recoverinorder(root,ino,idx);
       return; 
    }
};