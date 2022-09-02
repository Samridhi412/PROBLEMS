class Solution {
    int coinchange(vector<int> coins,int amount,int ind){
        if(ind==0){
            if(amount%coins[ind]==0){
                return amount/coins[ind];
            }
            else return INT_MAX;
        }
        int op1=coinchange(coins,amount,ind-1);
        int op2=INT_MAX;
        if(amount>=coins[ind])op2=coinchange(coins,amount-coins[ind],ind)+1;
        return min(op1,op2);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // return coinchange(coins,amount,n-1);
        vector<vector<long long>> dp(n,vector<long long>(amount+1,INT_MAX));
        dp[0][0]=0;
        for(int i=1;i<n;i++){
            dp[i][0]=0;
        }
        for(int j=1;j<=amount;j++){
            if(j%coins[0]==0){
                dp[0][j]=j/coins[0];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                long long op1=dp[i-1][j];
                long long op2=INT_MAX;
                if(j>=coins[i])op2=1+dp[i][j-coins[i]];
                dp[i][j]=min(op1,op2);
            }
        }
        return dp[n-1][amount]==INT_MAX?-1:dp[n-1][amount];
    }
};