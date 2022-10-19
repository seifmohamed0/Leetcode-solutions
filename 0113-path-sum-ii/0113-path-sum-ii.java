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
    HashMap<TreeNode , TreeNode> par = new HashMap<TreeNode , TreeNode>();
    List<List<Integer>> ret = new ArrayList<List<Integer>>();
    int targetSum;
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        if(root == null)return ret;
        this.targetSum = targetSum;
        dfs(root , null , 0);
        return ret;
    }
    // given leaf add path
    public void add_new_path(TreeNode node){
        List<Integer>list = new ArrayList<Integer>();
        while(node != null){
            list.add(node.val);
            node = par.get(node);
        }
        Collections.reverse(list);
        ret.add(list);
    }
    public void dfs(TreeNode node , TreeNode parent , int sum){
        sum += node.val;
        par.put(node , parent);
        if(node.left != null){
            dfs(node.left , node , sum);
        }
        if(node.right != null){
            dfs(node.right , node , sum);
        }
        if(node.left == null && node.right == null){
            if(sum == targetSum){
                add_new_path(node);
            }
        }
        return;
    }
}