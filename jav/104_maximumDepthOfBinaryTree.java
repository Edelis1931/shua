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
    public int maxDepth(TreeNode root) {
        return maxDepthHelper(root, 0, 0);
    }
    
    public int maxDepthHelper(TreeNode root, int maxDepth, int curDepth) {
        maxDepth = Math.max(maxDepth, curDepth);
        if (root == null) {
            return Math.max(maxDepth, curDepth);
        }else {
            return Math.max(maxDepthHelper(root.left, maxDepth, curDepth + 1), maxDepthHelper(root.right, maxDepth, curDepth + 1));
        }
    }
}