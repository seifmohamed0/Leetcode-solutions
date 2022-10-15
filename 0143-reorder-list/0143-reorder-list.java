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
    public void reorderList(ListNode head) {
        int n = 0;
        List<ListNode> list = new ArrayList<ListNode>();
        ListNode ptr = head;
        while(ptr != null){
            list.add(ptr);
            n++;
            ptr = ptr.next;
        }
        ListNode last = head;
        int ptr1 = 1 , ptr2 = n - 1;
        while(ptr2 >= ptr1){
            ListNode node = list.get(ptr2);
            last.next = node;
            last =  node;
            --ptr2;
            if(ptr2 >= ptr1){
                last.next = list.get(ptr1);
                last =  list.get(ptr1);
                ++ptr1; 
            }
        }
        last.next = null;
    }
}