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
    vector<int> result;
    vector<int> postorderTraversal(TreeNode* root) {
        if (root)
        {
            if (root->left)
            {
                postorderTraversal(root->left);
            }
            if (root->right)
            {
                postorderTraversal(root->right);
            }
            result.push_back(root->val);
        }
        
    return result;
    }
};