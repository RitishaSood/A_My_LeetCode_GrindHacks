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
class BSTiterator {
private :
      stack <TreeNode*> st;
      bool type;
      TreeNode* temp;
public:
    BSTiterator(TreeNode* root, bool t){
        temp = root;
        type = t;
        pushAll(root,type);
    }
    void pushAll(TreeNode* root, bool t){
        if(t==true){
            // for next;
            while(root){
                st.push(root);
                root = root->left;
            }
            return;

        }else{
            // for back
            while(root){
                st.push(root);
                root = root->right;
            }
            return;

        }
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        TreeNode* out = st.top();
        st.pop();
        if(type){
            if(out){
                pushAll(out->right,type);
            }
            return out->val;

        }else{
             if(out){
                pushAll(out->left,type);
            }
            return out->val;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTiterator after(root,true);
        BSTiterator before(root,false);
        int x = after.next();
        int y = before.next();
        while(x < y){
            if(x+y == k){
                return true;
            }else if(x+y < k){
                x = after.next();
            }else{
                y = before.next();
            }
        }
        return false;
        
    }
};