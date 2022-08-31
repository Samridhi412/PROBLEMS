class Solution {
    int total_money(vector<int>& nums,int ind){
        if(ind<0){
            return 0;
        }
        int op1=total_money(nums,ind-1);
        int op2=total_money(nums,ind-2)+nums[ind];
        return max(op1,op2);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            int op1=dp[i-1];
            int op2=-1e9;
            if(i>=2)op2=dp[i-2]+nums[i-1];
            dp[i]= max(op1,op2);
        }
        return dp[n];
        // return total_money(nums,n-1);
    }
};