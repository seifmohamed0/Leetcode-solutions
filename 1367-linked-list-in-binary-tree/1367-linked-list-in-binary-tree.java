/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
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
    TreeNode root;
    ListNode head ;
    public boolean valid(TreeNode node , ListNode head){
        if(head == null)
            return true;
        if(node == null)
            return false;
        if(node.val != head.val)
            return false;
        return valid(node.left , head.next) | valid(node.right , head.next);
    }
    public boolean dfs(TreeNode root){
        if(root == null)
            return false;
        if(root.val == head.val){
            if(valid(root , head))
                return true;
        }
        return dfs(root.left) | dfs(root.right);
    }
    public boolean isSubPath(ListNode head, TreeNode root) {
        this.head = head;
        this.root = root;
        return dfs(root);
    }
}