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
        vector<vector<int>> dp(n,vector<int>(m,-1));
       return wildcard(s,p,n-1,m-1,dp);
       
    }
};