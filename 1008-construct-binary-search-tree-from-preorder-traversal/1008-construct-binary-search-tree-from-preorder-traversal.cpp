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
    TreeNode* bst_construct(vector<int>& preorder,int l,int h){
        if(l<=h){
            TreeNode* newnode=new TreeNode(preorder[l]);
            int val=preorder[l];
            int kk;
            for(kk=l+1;kk<=h;kk++){
                if(preorder[kk]>val){
                    break;
                }
            }
            newnode->left=bst_construct(preorder,l+1,kk-1);
            newnode->right=bst_construct(preorder,kk,h);
            return newnode;
        }
        return NULL;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        return bst_construct(preorder,0,n-1);
    }
};