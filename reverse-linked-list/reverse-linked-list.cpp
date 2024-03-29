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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* curr = head;
        ListNode* prv = head;
        ListNode* nxt = head;
        curr = curr->next;
        while(curr){
            nxt = curr->next;
            if(prv == head){
                prv->next = NULL;
            }
            curr->next = prv;
            prv = curr;
            curr = nxt;
        }
        return prv;
    }
};