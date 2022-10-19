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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ret = new ArrayList<Integer>();
        if(root == null)
            return ret;
        List<TreeNode> list = new ArrayList<TreeNode>();
        list.add(root);
        while(list.isEmpty() == false){
            int sz = list.size();
            ret.add(list.get(sz - 1).val);
            List<TreeNode> new_list = new ArrayList<TreeNode>();
            for(int i = 0; i < sz ; i++){
                if(list.get(i).left != null)
                    new_list.add(list.get(i).left);
                if(list.get(i).right != null)
                    new_list.add(list.get(i).right);
            }
            list = new_list;
        }
        return ret;
    }
}