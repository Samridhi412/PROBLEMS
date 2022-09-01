class Solution {
    int min_squares(int n){
        if(ceil(double(sqrt(n)))==floor(double(sqrt(n)))){
            return 1;
        }
        int mini=n;
        for(int i=1;i*i<=n;i++){
            mini=min(mini,1+min_squares(n-i*i));
        }
        return mini;
    }
public:
    int numSquares(int n) {
        // return min_squares(n);
        vector<int> dp(n+1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int mini=i;
            for(int j=1;j*j<=i;j++){
                mini=min(mini,1+dp[i-j*j]);
            }
            dp[i]=mini;
        }
        return dp[n];
    }
};