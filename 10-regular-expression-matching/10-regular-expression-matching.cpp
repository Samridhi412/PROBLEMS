class Solution {
    bool regular_expression(string& s,string& p,int i,int j,vector<vector<int>>& dp){
        if(i<0&&j<0)return true;
       else if(j<0&&i>=0){
            return false;
        }
        else if(j>=0&&i<0){
            if(p[j]=='*') return regular_expression(s,p,i,j-2,dp);
            else return false;
        }
        else if(dp[i][j]!=-1)return dp[i][j];
        else if(s[i]==p[j]||p[j]=='.'){
            return dp[i][j]=regular_expression(s,p,i-1,j-1,dp);
        }
        else if(p[j]=='*'){
            bool op1=regular_expression(s,p,i,j-2,dp);
            bool op2=false;
            if(s[i]==p[j-1]||p[j-1]=='.'){
                op2=regular_expression(s,p,i-1,j,dp);
            }
            return dp[i][j]=op1||op2;
        }
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return regular_expression(s,p,n-1,m-1,dp);
    }
};