/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* headA2 = headA;
        ListNode* headB2 = headB;
        int cnt = 0;
        while(headA != headB && cnt < 3){
            headA = headA->next;
            headB = headB->next;
            if(headA == NULL){
                headA = headB2;
                ++cnt;
            }
            if(headB == NULL){
                headB = headA2;
                ++cnt;   
            }
        }
        if(cnt >= 3)return NULL;
        return headA;
    }
};