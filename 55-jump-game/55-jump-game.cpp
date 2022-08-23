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
        vector<int> dp(n,0);
        // return helper(nums,0,n,dp);
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==0){
                dp[i]=0;
                continue;
            }
            for(int j=1;j<=nums[i];j++){
                if(dp[i+j]){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[0];
    }
};