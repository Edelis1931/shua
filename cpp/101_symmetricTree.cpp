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
    bool isSymmetric(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        
        return isSymmetricHelper(root->left, root->right);
    }
    
    bool isSymmetricHelper(TreeNode* node1, TreeNode* node2)
    {
        if (node1 && node2)
        {
            if (node1->val != node2->val)
            {
                return false;
            }
            else
            {
                return (isSymmetricHelper(node1->left, node2->right) && isSymmetricHelper(node1->right, node2->left));
            }
        }
        else if(!node1 && !node2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
};