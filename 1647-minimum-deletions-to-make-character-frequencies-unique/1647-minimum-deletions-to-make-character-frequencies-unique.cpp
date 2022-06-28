class Solution {
public:
    int minDeletions(string s) {
        if(s.size()==1)return 0;
        int ans=0;
        set<int> st;
        int n=s.size();
        sort(s.begin(),s.end());
        for(int i=0;i<n-1;i++){
            int count=1;
            while(i<n&&s[i]==s[i+1]){
                count++;
                i++;
            }
            while(st.find(count)!=st.end()){
                ans++;
                count--;
            }
            if(count)st.emplace(count);
        }
        if(s[n-1]!=s[n-2]){
            if(st.count(1))ans++;
        }
        return ans;
    }
};