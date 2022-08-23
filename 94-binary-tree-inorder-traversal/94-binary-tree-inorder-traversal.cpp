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
    void helper(TreeNode* root,vector<int>& res){
        if(!root){
            return;
        }
        helper(root->left,res);
        res.push_back(root->val);
        helper(root->right,res);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        // helper(root,res);
        stack<TreeNode*> st;
        TreeNode* temp=root;
        while(1){
          
           if(temp){
               st.push(temp);
               temp=temp->left;
           }
            else{
                if(st.empty())break;
                temp=st.top();
                res.push_back(st.top()->val);
                st.pop();
                temp=temp->right;
            }
            
        }
        return res;
    }
};