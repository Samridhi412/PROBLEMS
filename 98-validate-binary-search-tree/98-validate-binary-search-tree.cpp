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
#define INT_MAX pow(2,31)+5
#define INT_MIN -pow(2,31)-5
class Solution {
    bool helper(TreeNode* root,long long min,long long max){
        if(!root){
            return true;
        }
        if(root->val>min&&root->val<max)return helper(root->left,min,root->val)&&helper(root->right,root->val,max);
        else return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,INT_MIN,INT_MAX);
    }
};