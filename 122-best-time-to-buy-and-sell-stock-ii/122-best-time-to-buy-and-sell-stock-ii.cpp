class Solution {
    int helper(vector<int>& nums,int ind,int n, vector<vector<int>>& dp,bool isbuy=1){
        if(ind==n){
            return 0;
        }
        else if(dp[ind][isbuy]!=-1)return dp[ind][isbuy];
        if(isbuy){
            int op1=helper(nums,ind+1,n,dp,0)-nums[ind];
            int op2=helper(nums,ind+1,n,dp,1);
            dp[ind][isbuy]= max(op1,op2);
        }
        else{
            int op1=helper(nums,ind+1,n,dp,1)+nums[ind];
            int op2=helper(nums,ind+1,n,dp,0);
            dp[ind][isbuy]= max(op1,op2);
        }
        return dp[ind][isbuy];
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(prices,0,prices.size(),dp);
    }
};