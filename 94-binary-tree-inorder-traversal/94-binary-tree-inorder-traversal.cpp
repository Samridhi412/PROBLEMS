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
    vector<int> inorderTraversal(TreeNode* node) {
        if(!node)return {};
        vector<int> inorder;
        // stack<TreeNode*> st;
        // while(1){
        //     if(node){
        //         st.push(node);
        //         node=node->left;
        //     }
        //     else{
        //         if(st.empty())break;
        //         TreeNode* value=st.top();
        //         inorder.push_back(value->val);
        //         st.pop();
        //         node=value->right;
        //     }
        // }
        TreeNode* root=node;
        while(root){
            if(root->left==NULL){
                inorder.push_back(root->val);
                root=root->right;
            }
            else{
                TreeNode* prev=root->left;
                while(prev->right&&prev->right!=root){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=root;
                    root=root->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(root->val);
                    root=root->right;
                }
            }
        }
        return inorder;
    }
};