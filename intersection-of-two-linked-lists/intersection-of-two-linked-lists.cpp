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
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode* L1 = headA;
        ListNode* L2 = headB;
        int cnt = 0;
        while(L1 != L2 && cnt < 3){
            L1 = L1->next;
            L2 = L2->next;
            if(L1 == NULL){
                L1 = headB ;
                ++cnt;
            }
            if(L2 == NULL){
                L2 = headA ;
                ++cnt;
            }
        }
        if(cnt > 2)
            return NULL;
        return L1;
    }
};