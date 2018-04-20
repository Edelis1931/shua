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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> temp;
        pathSumHelper(root, sum, result, temp);
        return result;
    }
    
    void pathSumHelper(TreeNode* root, int sum, vector<vector<int>> &result, vector<int> &temp)
    {
        if (root)
        {
            //先推入这个root
            temp.push_back(root->val);
            
            if (!root->left && !root->right)
            {
                int length = 0;
                for (int i = 0; i < temp.size(); i++)
                {
                    length += temp.at(i);
                }
                if (length == sum)
                {
                    result.push_back(temp);
                }
            }
            else
            {
                if (root->left) pathSumHelper(root->left, sum, result, temp);
                if (root->right) pathSumHelper(root->right, sum, result, temp);
            }
            
            //用完以后要去掉
            temp.pop_back();
        }
    }
};