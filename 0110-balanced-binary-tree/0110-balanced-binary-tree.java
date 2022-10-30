/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isBalanced(TreeNode root) {
        return height(root, 1) > 0;
    }

    private int height(TreeNode root, int height) {
        if(root == null ) return height;

        int left = height(root.left, height+1);
        int right = height(root.right, height+1);

        if(left < 0 || right < 0 || Math.abs(left-right) > 1) return -1; //Fail fast

        return Math.max(left, right);
    }
}