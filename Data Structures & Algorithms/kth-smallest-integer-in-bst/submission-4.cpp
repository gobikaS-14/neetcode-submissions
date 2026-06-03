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


//brute force-using array
/*
class Solution {
public:
    vector<int> res;
    void inorder(TreeNode* root){
        if(root==NULL)  return;
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return res[k-1];
    }
    
};
*/
//optimal->no array
class Solution {
public:
    int count=0;
    int ans;
    void inorder(TreeNode* root,int k){
        if(root==NULL)  return;

        inorder(root->left,k);
        count++;
        //visting root
        if(count==k){
            ans=root->val;
            return;
        }   
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
    
};

