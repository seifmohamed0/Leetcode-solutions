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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* curr = head;
        ListNode* nxt = head->next;
        ListNode* prv = NULL;
        while(curr != NULL && nxt != NULL){
            ListNode* fw = nxt->next;
            nxt->next = curr;
            curr->next = fw;
            if(prv != NULL){
                prv->next = nxt;
            }else{
                head = nxt;   
            }
            prv = curr;
            curr = fw;
            if(fw != NULL)
                nxt = fw->next;
        }
        return head;
    }
};