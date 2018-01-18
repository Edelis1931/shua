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
        bool hasPathSum(TreeNode* root, int sum) {
            bool result = false;
            pathSumHelper(root, sum, 0, result);
            return result;
        }

        void pathSumHelper(TreeNode* root, int sum, int previous, bool& res)
        {
            if (root) {
                if (!root->left && !root->right)
                {
                    if (sum == previous + root->val)
                    {
                        res = true;
                    }
                }
                else
                {
                    if (root->left) pathSumHelper(root->left, sum, previous + root->val, res);
                    if (root->right) pathSumHelper(root->right, sum, previous + root->val, res);
                }
            }
        }
};
