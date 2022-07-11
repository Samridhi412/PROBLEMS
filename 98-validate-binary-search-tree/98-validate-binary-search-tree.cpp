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
    bool isvalid(TreeNode* root,long long min,long long max){
        if(!root)return true;
        if(root->val<=min||root->val>=max)return false;
        bool left=isvalid(root->left,min,root->val);
        bool right=isvalid(root->right,root->val,max);
        return left&&right;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isvalid(root,INT_MIN,INT_MAX);
    }
};