/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;
        int sz = 0;
        ListNode* node = head;
        while(node != NULL){
            ++sz;
            node = node->next;
        }
        sz -= n;
        if(!sz){
            head = head->next;
            return head;
        }
        ListNode* prv = head ;
        ListNode* curr = head;
        while(sz){
            curr = curr->next;
            --sz;
            if(!sz){
                prv->next = curr->next;
                return head;
            }
            prv = prv->next;
        }
        return head;
    }
};