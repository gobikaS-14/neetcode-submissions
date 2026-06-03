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
 //brute force
 
class Solution {
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // base case
        if (preorder.size() == 0) return NULL;

        // root from preorder
        int rootValue = preorder[0];
        TreeNode* root = new TreeNode(rootValue);

        // find position in current inorder
        int pos = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootValue) {
                pos = i;
                break;
            }
        }
        // create left and right inorder
        vector<int> leftIn(inorder.begin(), inorder.begin() + pos);
        vector<int> rightIn(inorder.begin() + pos + 1, inorder.end());

        // create left and right preorder
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + leftIn.size());
        vector<int> rightPre(preorder.begin() + 1 + leftIn.size(), preorder.end());

        // recursive calls
        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);

        return root;
    }
};