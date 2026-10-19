class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
          //your code goes here
           vector<int> ans;
        //    preorderR(root,ans);
           stack<TreeNode*> st;
           while(root || !st.empty()){
            while(root){
                ans.push_back(root->val);
                st.push(root);
                root=root->left;
            }
            root = st.top();
            st.pop();
            root = root->right;
           }
           return ans;
    }
};