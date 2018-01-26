/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        flatternHelper(root);
    }
    
    void flatternHelper(TreeNode* root)
    {
        if (!root) return;
        
        flatternHelper(root->left);
        flatternHelper(root->right);
        
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = 0;
        while (root->right) root = root->right;
        root->right = temp;
    }
};