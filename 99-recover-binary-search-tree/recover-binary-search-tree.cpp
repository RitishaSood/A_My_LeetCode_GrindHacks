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
private:
    TreeNode* first;
    TreeNode* second;
    TreeNode* prev;
    TreeNode* middle;
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
    void pointers(TreeNode* root){
        if(!root)return;
        pointers(root->left);
        if(prev!= nullptr && (prev->val > root->val)){
            if(first == nullptr){
                first = prev;
                middle = root;
            }else{
                second = root;
            }
        }
        prev = root;
        pointers(root->right);
        
    }
public:
    void recoverTree(TreeNode* root) {
       //your code goes here
    //    vector<int> ino;
    //    int idx = 0;
    //    trackinorder(root,ino);
    //    sort(ino.begin(),ino.end());
    //    recoverinorder(root,ino,idx);
    //    return;

    first = prev = second= nullptr;
       pointers(root);
       if(second){
        swap(first->val,second->val);
       }else{
        swap(first->val, middle->val);
       }
       return; 
    }
};