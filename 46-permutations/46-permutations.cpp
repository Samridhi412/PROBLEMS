class Solution {
    void helper(vector<int>& nums,vector<vector<int>>& res,int ind,int n){
        if(ind==n){
            res.push_back(nums);
            return;
        }
        for(int i=ind;i<n;i++){
            swap(nums[i],nums[ind]);
            helper(nums,res,ind+1,n);
            swap(nums[i],nums[ind]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums,res,0,nums.size());
        return res;
    }
};