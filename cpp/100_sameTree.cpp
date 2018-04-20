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
        bool isSameTree(TreeNode* p, TreeNode* q) {

            if (!p && !q)
            {
                std::cout << "conditoin 1" << std::endl;
                return true;
            }
            else if (p && q)
            {
                std::cout << "conditoin 2" << std::endl;
                return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
            }
            else
            {
                std::cout << "conditoin 3" << std::endl;
                return false;
            }
        }
};
