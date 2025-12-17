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
        if (root == nullptr) {
            return "";
        }

        string result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                result += "null,";
                continue;
            }
            result += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        vector<string> nodes;
        string temp;
        // Split string by comma
        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int index = 1;
        while (!q.empty() && index < nodes.size()) {
            TreeNode* current = q.front();
            q.pop();
            // Left child
            if (nodes[index] != "null") {
                current->left = new TreeNode(stoi(nodes[index]));
                q.push(current->left);
            }
            index++;
            // Right child
            if (index < nodes.size() && nodes[index] != "null") {
                current->right = new TreeNode(stoi(nodes[index]));
                q.push(current->right);
            }
            index++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));