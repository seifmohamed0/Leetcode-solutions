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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) 
            return head;
        int cnt = 1; 
        ListNode *head2;
        ListNode *tail;
        head2 = tail = head;
        while(tail->next){
            tail = tail->next;
            cnt++;
        }
        tail->next = head;

        if(k %= cnt) {
            for(auto i = 0; i < cnt - k; i++)
                tail = tail->next; 
        }
        head2 = tail->next; 
        tail->next = NULL;
        return head2;
    }
};