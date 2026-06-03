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

//BRUTE FORCE
/*
class Solution {
public:
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if(root==NULL)  return false;
        path.push_back(root);
        if(root==target)    return true;

        if(findPath(root->left,target,path) ||findPath(root->right,target,path)) return true;

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> pathP, pathQ;

        findPath(root, p, pathP);
        findPath(root, q, pathQ);
        int n=pathP.size();
        int m=pathQ.size();
        int i=0;
        TreeNode* lca=NULL;
        while(i<n && i<m){
            if(pathP[i]==pathQ[i])  lca=pathP[i];
            else
                break;
            i++;
        }
      return lca; 
    }
};*/

class Solution {
    public: 
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

            while(root!=NULL){
                if(p->val<root->val && q->val<root->val)    root=root->left;
                else if (p->val>root->val && q->val>root->val)    root=root->right;
                else    return root;
            }
            return NULL;
        }
};        
