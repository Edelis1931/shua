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
        int sumNumbers(TreeNode* root) {
            return sumHelper(root);
        }

        int sumHelper(TreeNode* root, int previousValue = 0)
        {
            if (!root)
            {
                //这里不能是previousValue
                return 0;
            }
            //这句话是核心
            else if (!root->left && !root->right)
            {
                return previousValue*10 + root->val;
            }
            else
            {
                return sumHelper(root->left, previousValue*10 + root->val) + sumHelper(root->right, previousValue*10 + root->val);
            }
        }
};
