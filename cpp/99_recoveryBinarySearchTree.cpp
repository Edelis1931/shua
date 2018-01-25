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
    int p1;
    int p2;
    int first;
    int second;
    vector<int> allNodes;
    public:
    void recoverTree(TreeNode* root) {
        //let's traverse the list first
        inOrderTraversal(root);
        int count = allNodes.size();
        if (count < 2) return;

        //this counter counts the number of p2 > p1
        int counter = 0;

        p1 = allNodes.at(0);
        p2 = allNodes.at(0);
        first = INT_MIN;
        second = INT_MAX;

        for (int i = 1; i < count; i++)
        {
            p2 = allNodes.at(i);
            if (p2 < p1 && counter == 0)
            {
                first = p1;
                second = p2;
                counter++;
            }
            else if (p2 < p1 && counter == 1)
            {
                second = p2;
            }
            p1 = allNodes.at(i);
        }

        //now we have first and second
        fixTree(root);
    }

    void inOrderTraversal(TreeNode* root)
    {
        if (!root)
        {
            return;
        }

        inOrderTraversal(root->left);
        allNodes.push_back(root->val);
        inOrderTraversal(root->right);
    }

    void fixTree(TreeNode* root)
    {
        if (!root)
        {
            return;
        }

        fixTree(root->left);
        if (root->val == first)
        {
            root->val = second;
        }else if(root->val == second)
        {
            root->val = first;
        }

        fixTree(root->right);
    }
};
