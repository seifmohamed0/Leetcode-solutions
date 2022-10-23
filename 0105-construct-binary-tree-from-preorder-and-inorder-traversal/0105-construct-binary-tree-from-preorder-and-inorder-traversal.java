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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        List<Integer> preOrder = new ArrayList<>();
        List<Integer> inOrder = new ArrayList<>();
        for(int pre: preorder) preOrder.add(pre);
        for(int in: inorder) inOrder.add(in);
        return fun(preOrder,inOrder);
    }
    private TreeNode fun(List<Integer> preOrder, List<Integer> inOrder){
        if(preOrder.isEmpty()) return null;
        if(preOrder.size() == 1) return new TreeNode(preOrder.get(0));
        int index = inOrder.indexOf(preOrder.get(0));
        TreeNode root = new TreeNode(preOrder.get(0));
        root.left = fun(preOrder.subList(1,1+index),inOrder.subList(0,index));
        root.right = fun(preOrder.subList(1+index,preOrder.size()),inOrder.subList(1+index,inOrder.size()));
        return root;
    }
}