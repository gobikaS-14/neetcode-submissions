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
    bool isSameTree(TreeNode* t1, TreeNode* t2) {
        //base case:1
            if(t1==NULL && t2==NULL) return true;
        //base case:2
            if(t1 == NULL || t2 == NULL) return false;
        //base case:3
            if(t1->val!=t2->val)    return false;
        // Check left and right
            return isSameTree(t1->left,t2->left) && isSameTree(t1->right,t2->right);

    }

    bool isSubtree(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL)  return false;
        if(isSameTree(t1,t2))   return true;
        return  isSubtree(t1->left,t2) || isSubtree(t1->right,t2);
    }
};
