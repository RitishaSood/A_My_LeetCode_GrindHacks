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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr;
        }
        if(root->val == key){
            return connector(root);
        }else{
            TreeNode* temp = root;
            while(temp){
                if(temp->val > key){
            if(temp->left && temp->left->val == key){
                TreeNode* del = temp->left;
                temp->left = connector(del);
                break;
            }
            temp = temp->left;
            }else{
                if(temp->right && temp->right->val == key){
                TreeNode* del = temp->right;
                temp->right = connector(del);
                break;
                }
               temp = temp->right;
            }
            }
        }
        return root;
        
    }
    TreeNode* connector(TreeNode* Node){
        if(Node->left == nullptr){
            return Node->right;
        }else if(Node->right == nullptr){
            return Node->left;
        }else{
            TreeNode* temp = Node->right;
            TreeNode* lefter = Node->left;
            while(temp->left){
                    temp = temp->left;
            }
            temp->left = lefter;
        }
        return Node->right;
    }
};