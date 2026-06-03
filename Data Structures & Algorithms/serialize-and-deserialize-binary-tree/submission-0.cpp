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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)  return "null";

        queue<TreeNode*>q;
        string res="";

        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(node == NULL){
                res += "null,";
                continue;
           }
                res+=to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
        }
        return res;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        //create a ll with root
        if(str=="null") return NULL;
        TreeNode* root=new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            //left child
            getline(ss,str,',');
            if(str=="null")  node->left=NULL;
            else{
                node->left=new TreeNode(stoi(str));
                q.push(node->left);
            }

            getline(ss,str,',');
            if(str=="null")  node->right=NULL;
            else{
                node->right=new TreeNode(stoi(str));
                q.push(node->right);
            }
            
        }
    return root;    
    }
};
