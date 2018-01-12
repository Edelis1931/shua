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
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        int curDepth = 0;
        maxDepthHelper(root, maxDepth, curDepth);
        return maxDepth;
    }
    
    void maxDepthHelper(TreeNode* root, int& maxDepth, int& curDepth)
    {
        if (root)
        {
            curDepth += 1;
                
            if (!root->left && !root->right)
            {
                maxDepth = std::max(maxDepth, curDepth);
            }
            else
            {
                if (root->left) maxDepthHelper(root->left, maxDepth, curDepth);
                if (root->right) maxDepthHelper(root->right, maxDepth, curDepth);
            }

        curDepth -= 1;
        }
    }
};
