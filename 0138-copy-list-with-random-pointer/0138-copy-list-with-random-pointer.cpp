/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
private:
    map<Node *, Node *> mp;
public:
    Node *copyRandomList(Node *head, Node *result = nullptr) {
        if (!head) 
            return head;
        result = new Node(head->val);
        mp[head] = result;
        result->next = copyRandomList(head->next, result->next);
        result->random = mp[head->random];
        return result;
    }
};