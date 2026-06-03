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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        
        // base case
        if(preorder.size() == 0) return NULL;

        // step 1: root from preorder
        int rootValue = preorder[0];
        TreeNode* root = new TreeNode(rootValue);

        // step 2: find root in inorder
        int pos = mp[rootValue];

        // step 3: create left & right inorder
        vector<int> leftIn(inorder.begin(), inorder.begin() + pos);
        vector<int> rightIn(inorder.begin() + pos + 1, inorder.end());

        // step 4: split preorder
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + leftIn.size());
        vector<int> rightPre(preorder.begin() + 1 + leftIn.size(), preorder.end());

        // step 5: recursive build
        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);

        return root;
    }
};
