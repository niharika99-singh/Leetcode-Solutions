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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode* > s;
        TreeNode* curr=root;
        TreeNode* prev=NULL;
        
        while(curr || !s.empty()){
            while(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            
            curr=s.top();
            s.pop();
            if(prev!=NULL && curr->val<=prev->val)
                return false;
            
            prev=curr;
            
            curr=curr->right;
        }
        
        return true;
    }
};