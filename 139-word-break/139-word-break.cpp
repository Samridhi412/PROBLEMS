class Solution {
    bool partition(string& s,set<string>& st,int ind,int n){
        if(ind==n){
            return true;
        }
        for(int i=ind;i<n;i++){
            string str=s.substr(ind,i-ind+1);
            if(st.count(str)){
                 if(partition(s,st,i+1,n))return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        int n=s.size();
        int m=wordDict.size();
        for(int i=0;i<m;i++){
            st.insert(wordDict[i]);
        }
        // return partition(s,st,0,s.size());
        vector<int> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    string str=s.substr(j,i-j);
                    if(st.count(str)){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};