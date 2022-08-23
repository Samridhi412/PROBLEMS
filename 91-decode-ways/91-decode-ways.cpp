class Solution {
    int helper(string& s,int ind){
        if(ind==s.size()){
            return 1;
        }
        else if(s[ind]=='0'){
            return 0;
        }
        int op1=helper(s,ind+1);
        int op2=0;
        if(ind<s.size()-1&&((s[ind]=='1')||(s[ind]=='2'&&s[ind+1]-'0'<=6))){
            op2=helper(s,ind+2);
        }
        return op1+op2;
    }
public:
    int numDecodings(string s) {
        // return helper(s,0);
        int n=s.size();
        int dp[n+1];
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;
                continue;
            }
             int op1=dp[i+1];
            int op2=0;
            if(i<n-1&&((s[i]=='1')||(s[i]=='2'&&s[i+1]-'0'<=6))){
                op2=dp[i+2];
            }
            dp[i]= op1+op2;
            }
        return dp[0];
    }
};