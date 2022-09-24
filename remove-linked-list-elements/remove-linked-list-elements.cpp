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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val){
            head = head->next;
        }
        if(head == NULL)
            return head;
        ListNode* prv = head;
        ListNode* curr = head->next;
        while(curr != NULL){
            if(curr->val == val){
                prv->next = curr->next;
                curr = curr->next;
            }else{
                prv = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};