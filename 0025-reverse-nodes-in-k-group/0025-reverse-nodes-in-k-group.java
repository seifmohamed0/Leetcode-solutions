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
    public ListNode reverseKGroup(ListNode head, int k) {
        int n = 0;
        ListNode ptr = head;
        while(ptr != null){
            ++n;
            ptr = ptr.next;
        }
        int curr = 0;
        ptr = head;
        ListNode prv = null;
        while(curr + k <= n){
            List<ListNode> list = new ArrayList<ListNode>();
            int k2 = k;
            while(k2 > 0){
                --k2;
                list.add(ptr);
                ptr = ptr.next;
            }
            if(prv != null){
                prv.next = list.get(k - 1);
            }else{
                head = list.get(k - 1);
            }
            list.get(0).next = ptr;
            for(int i = k - 1 ; i > 0 ; i--){
                list.get(i).next = list.get(i -1);
            }
            prv = list.get(0);
            curr += k;
        }
        return head;
    }
}