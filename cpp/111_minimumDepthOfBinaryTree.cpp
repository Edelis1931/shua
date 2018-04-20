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
    int minDepth(TreeNode* root) {
        int minDepth = INT_MAX;
        int curDepth = 0;
        if (!root) return 0;
        minDepthHelper(root, minDepth, curDepth);
        return minDepth;
    }
    
    void minDepthHelper(TreeNode* root, int& minDepth, int& curDepth)
    {
        if (root)
        {
            curDepth += 1;
            
            if (!root->left && !root->right)
            {
                minDepth = std::min(minDepth, curDepth);
            }
            else
            {
                if (root->left) minDepthHelper(root->left, minDepth, curDepth);
                if (root->right) minDepthHelper(root->right, minDepth, curDepth);
            }
            
        curDepth -= 1;
        }
    }
};