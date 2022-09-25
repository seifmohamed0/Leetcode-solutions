/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool Compare(TreeNode* u , TreeNode* v){
        if(u ==NULL && v == NULL)
            return true;
        if(u == NULL || v == NULL)
            return false;
        if(u->val != v->val)
            return false;
        return Compare(u->left , v->left) & Compare(u->right , v->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL){
            return subRoot == NULL;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr =q.front();
            q.pop();
            if(curr->val == subRoot->val){
                if(Compare(curr , subRoot))
                    return true;
            }
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        return false;
    }
};