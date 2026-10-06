/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // for serialisation I am planning to go with the level order traversal
        // how ?
        if (!root) return "";
        string s ="";
        queue<TreeNode*> q;
        TreeNode* temp = root;
        q.push(temp);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* out = q.front();
                q.pop();
                if(out!=nullptr){
                string data = to_string(out->val)+ ",";
                s+=data;
                q.push(out->left);
                q.push(out->right);
                }else{
                s+="#,";
                }
            }
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // in string i, i+1 left, i+2 right;
        // for this also i will need another traversal
        if (data.empty()) return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        TreeNode* temp = root;
        queue<TreeNode*> q;
        q.push(temp);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* out = q.front();
                q.pop();
                if(getline(s,str,',')){
                if(str != "#"){
                    TreeNode* left_node = new TreeNode(stoi(str));
                    out->left = left_node;
                    q.push(left_node);
                }
                }
                if(getline(s,str,',')){
                if(str != "#"){
                    TreeNode* right_node = new TreeNode(stoi(str));
                    out->right = right_node;
                    q.push(right_node);
                }
                }

            

        }
        }

      return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));