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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

            vector<vector<int>> result;

            queue<TreeNode*> myqueue;

            if (root)
            {
                myqueue.push(root);
            }

            int ltor = 0;

            while (!myqueue.empty())
            {
                vector<int> tempResult;
                int curSize = myqueue.size();
                for (int i = 0; i < curSize; i++)
                {
                    TreeNode* getNode = myqueue.front();

                    if (getNode){
                        myqueue.push(getNode->left);
                        myqueue.push(getNode->right);

                        tempResult.push_back(getNode->val);
                        printf("%d\n", getNode->val);
                    }
                    myqueue.pop();
                }

                if (tempResult.size() != 0)
                {
                    if (ltor)
                    {
                        std::reverse(tempResult.begin(), tempResult.end());
                        ltor = 0;
                    }
                    else
                    {
                        ltor = 1;
                    }
                    result.push_back(tempResult);
                }
            }

            return result;
        }
};
