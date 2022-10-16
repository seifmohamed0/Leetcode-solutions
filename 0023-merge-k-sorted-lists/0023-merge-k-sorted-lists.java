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
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> bq = new PriorityQueue<>(new Comparator<ListNode>() {
            public int compare(ListNode n1, ListNode n2){
                return n1.val - n2.val;
            }
        });
        int k = lists.length;
        ListNode head = null;
        ListNode ptr = null;
        for(int i = 0; i < k; i++){
            if(lists[i] != null){
                bq.add(lists[i]);
            }
        }
        while(!bq.isEmpty()){
            ListNode curr = bq.poll();
            if(curr.next != null){
                bq.add(curr.next);
            }
            if(head == null){
                head = curr;
                ptr = head;
            }else{
                ptr.next = curr;
                ptr = ptr.next;
            }
        }
        return head;
    }
}