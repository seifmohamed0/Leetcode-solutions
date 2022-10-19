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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
         if(root == null)
            return ret;
        List<Integer> list = new ArrayList<Integer>();
        List<TreeNode> prv = new ArrayList<TreeNode>(); 
        list.add(root.val);
        prv.add(root);
        ret.add(list);
        boolean right = true;
        while(prv.isEmpty() == false){
            List<TreeNode> new_list = new ArrayList<TreeNode>();
            List<Integer> to_add = new ArrayList<Integer>();
            for(int i = prv.size() - 1 ; i >= 0 ; i--){
                if(right == true){
                    if(prv.get(i).right != null){
                        new_list.add(prv.get(i).right);
                        to_add.add(prv.get(i).right.val);
                    }
                    if(prv.get(i).left != null){
                        new_list.add(prv.get(i).left);
                        to_add.add(prv.get(i).left.val);
                    }
                }else{
                    if(prv.get(i).left != null){
                        new_list.add(prv.get(i).left);
                        to_add.add(prv.get(i).left.val);
                    }
                    if(prv.get(i).right != null){
                        new_list.add(prv.get(i).right);
                        to_add.add(prv.get(i).right.val);
                    }
                }
            }
            if(to_add.size() != 0){
                ret.add(to_add);
            }
            prv = new_list;
            right = right == false ? true : false;
        }
        return ret;
    }
}