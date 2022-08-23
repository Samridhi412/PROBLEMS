class Solution {
    bool wildcard(string& s,string& p,int i,int j,vector<vector<int>>& dp){
        if(i<0&&j<0){
            return true;
        }
        else if(i>=0&&j<0){
            return false;
        }
        else if(i<0&&j>=0){
            for(int kk=0;kk<=j;kk++){
                if(p[kk]!='*'){
                    return false;
                }
            }
            return true;
        }
        else if(dp[i][j]!=-1)return dp[i][j];
        else if(s[i]==p[j]||p[j]=='?'){
            return dp[i][j]=wildcard(s,p,i-1,j-1,dp);
        }
        else if(p[j]=='*'){
            return dp[i][j]=wildcard(s,p,i-1,j,dp)|| wildcard(s,p,i,j-1,dp);
        }
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
       // return wildcard(s,p,n-1,m-1,dp);
        dp[0][0]=1;
        for(int j=1;j<=m;j++){
            dp[0][j]=(p[j-1]=='*')&&dp[0][j-1];   
        }
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               if(s[i-1]==p[j-1]||p[j-1]=='?'){
                   dp[i][j]=dp[i-1][j-1];
               }
               else if(p[j-1]=='*'){
                   dp[i][j]=dp[i-1][j]||dp[i][j-1];
               }
               else{
                   dp[i][j]=0;
               }
           }
       }
        return dp[n][m];
    }
};