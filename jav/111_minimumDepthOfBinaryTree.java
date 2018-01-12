/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int minDepth(TreeNode root) {
        if (root == null) return 0;

        int minDepth = Integer.MAX_VALUE;
        int curDepth = 0;
        return minDepthHelper(root, minDepth, curDepth);
    }

    public int minDepthHelper(TreeNode root, int minDepth, int curDepth)
    {
        if (root == null)
        {
            return Integer.MAX_VALUE;
        }
        else
        {
            if (root.left == null && root.right == null)
            {
                return Math.min(minDepth, curDepth + 1);
            }
            else
            {
                int leftMin = minDepthHelper(root.left, minDepth, curDepth + 1);
                int rightMin = minDepthHelper(root.right, minDepth, curDepth + 1);
                return Math.min(leftMin, rightMin);
            }
        }
    }
}
