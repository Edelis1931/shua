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
        //this vector has to be treated as a global variable
        vector<int> result;

        vector<int> preorderTraversal(TreeNode* root) {
            if(root)
            {
                result.push_back(root->val);
                if (root->left)
                {
                    preorderTraversal(root->left);
                }
                if (root->right)
                {
                    preorderTraversal(root->right);
                }
            }

            return result;
        }
};
