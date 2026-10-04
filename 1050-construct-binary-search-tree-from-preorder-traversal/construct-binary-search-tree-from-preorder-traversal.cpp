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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        int n = preorder.size();
        sort(inorder.begin(),inorder.end());
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root;
        return buildtree(preorder,0,n-1,inorder,0,n-1,mpp);
    }
    TreeNode* buildtree(vector<int> preorder, int prestart, int preend, vector<int> inorder, int instart, int inend, map <int,int> mpp){
        if(prestart > preend || instart > inend){
            return nullptr;
        }
        int isrootidx = mpp[preorder[prestart]];
        int numleft = isrootidx - instart;
        TreeNode* root = new TreeNode(preorder[prestart]);
        root->left = buildtree(preorder,prestart+1,prestart+numleft,inorder,instart,isrootidx-1,mpp);
        root->right = buildtree(preorder,prestart+numleft+1,preend,inorder,isrootidx+1,inend,mpp);
        return root;
    }
};