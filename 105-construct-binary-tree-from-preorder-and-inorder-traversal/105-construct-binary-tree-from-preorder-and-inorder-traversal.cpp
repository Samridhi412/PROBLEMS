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
     TreeNode* buildtree(vector<int>& preorder,vector<int>& inorder,int pres,int pree,int ins,int ine){
         if(pres<=pree){
             int rpree=pree;
             int lpres=pres+1;
             int index=-1;
             for(int i=ins;i<=ine;i++){
                 if(inorder[i]==preorder[pres]){
                     index=i;
                     break;
                 }
             }
             int lins=ins;
             int line=index-1;
             int rins=index+1;
             int rine=ine;
             int size=index-ins;
             int lpree=pres+size;
             int rpres=lpree+1;
             TreeNode* newnode=new TreeNode(preorder[pres]);
             newnode->left=buildtree(preorder,inorder,lpres,lpree,lins,line);
             newnode->right=buildtree(preorder,inorder,rpres,rpree,rins,rine);
             return newnode;
         }
         return NULL;
     }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return buildtree(preorder,inorder,0,n-1,0,n-1);
    }
};