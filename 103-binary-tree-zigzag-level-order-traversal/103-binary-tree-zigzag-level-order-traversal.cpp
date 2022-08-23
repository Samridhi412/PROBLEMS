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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
         vector<vector<int>>  res;
        if(!root)return res;
        q.push(root);
        int lr=1;
        while(!q.empty()){
            int k=q.size();
            vector<int> temp(k);
            for(int i=0;i<k;i++){
                TreeNode* front=q.front();
                q.pop();
                int index=lr==1?i:k-1-i;
                temp[index]=front->val;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
             lr=!lr;
        res.push_back(temp);
        }
       return res;
    }
};