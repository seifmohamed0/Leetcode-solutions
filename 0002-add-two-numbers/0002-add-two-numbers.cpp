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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return l1;
        ListNode* ret = new ListNode;
        ListNode* ptr = ret;
        int sum = 0;
        bool flag = false;
        while(l1 != NULL || l2 != NULL || sum){
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            if(!flag){
                ptr->val = sum % 10;
                flag = true;
            }else{
                ptr->next = new ListNode(sum % 10);
                ptr = ptr->next;
            }
            sum /= 10;
        }
        
        return ret;
    }
};