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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while(1){
            while(root){
                st.push(root);
                root=root->left;
            }
            if(!st.empty()){
                TreeNode* ele=st.top();
                st.pop();
                if(--k==0)return ele->val;
                // cout<<k<<endl;
                root=ele->right;
            }
            else{
                break;
            }
        }
        return -1;
    }
};