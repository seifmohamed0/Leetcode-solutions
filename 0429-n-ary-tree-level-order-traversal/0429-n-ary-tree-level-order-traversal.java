/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        if(root == null)
            return ret;
        List<Integer>prv_val = new ArrayList<Integer>();
        List<Node>prv_node = new ArrayList<Node>();
        prv_node.add(root);
        prv_val.add(root.val);
        while(!prv_node.isEmpty()){
            ret.add(prv_val);
            List<Integer>curr_val = new ArrayList<Integer>();
            List<Node>curr_node = new ArrayList<Node>();
            for(int i = 0 ; i < prv_node.size() ; i++){
                Node node = prv_node.get(i);
                for(int j = 0 ; j < node.children.size() ; j++){
                    curr_node.add(node.children.get(j));
                    curr_val.add(node.children.get(j).val);
                }
            }
            prv_node = curr_node;
            prv_val = curr_val;
        }
        return ret;
    }
}