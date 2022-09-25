/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* connect(Node* root) {
        if(root == NULL)
            return NULL;
        root->next = NULL;
        queue<Node*>q;
        if(root->left != NULL){
            q.push(root->left);
        } 
        if(root->right != NULL){
            q.push(root->right);
        }
        while(!q.empty()){
            int sz = q.size();
            int cnt = 1;
            Node* curr = q.front();
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
            q.pop();
            while(cnt != sz){
                ++cnt;
                Node* nxt = q.front();
                q.pop();
                curr->next = nxt;
                curr = nxt;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            curr->next = NULL;
        }
        return root;
    }
};