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
        bool isBalanced(TreeNode* root) {
            return isBalancedHelper(root);
        }

        int maxDepth(TreeNode* root)
        {
            if (!root) return 0;

            return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }

        bool isBalancedHelper(TreeNode* root)
        {
            if (!root) return true;

            return (std::abs(maxDepth(root->left) - maxDepth(root->right)) <=1 ) && isBalancedHelper(root->left) && isBalancedHelper(root->right);

        }
};
