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
    unordered_map<int,int> mpp;
    void right_view(TreeNode* root,int level,vector<int>& res){
        if(!root)return;
        if(level==res.size()){
            // mpp[level]=root->val;
            res.push_back(root->val);
        }
        right_view(root->right,level+1,res);
        right_view(root->left,level+1,res);
        
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
       right_view(root,0,res);
        return res;
    }
};