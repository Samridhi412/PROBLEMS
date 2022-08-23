class Solution {
    bool helper(vector<int>& nums,int ind,int n,vector<int>& dp){
        if(ind==n-1){
            return true;
        }
        else if(nums[ind]==0){
            return false;
        }
        else if(dp[ind]!=-1)return dp[ind];
        for(int i=1;i<=nums[ind];i++){
            if(helper(nums,ind+i,n,dp)){
                return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return helper(nums,0,n,dp);
    }
};