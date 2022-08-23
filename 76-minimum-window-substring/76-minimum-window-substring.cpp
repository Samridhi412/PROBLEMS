class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int> mp;
        for(auto x:t){
            mp[x]++;
        }
        int count=mp.size();
        int j=0,i=0;
        int maxlen=INT_MAX;
        string res;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            if(count==0){
                while(count==0){
                    if(maxlen>j-i+1){
                        maxlen=j-i+1;
                        res=s.substr(i,j-i+1);
                    }
                    // maxlen=min(maxlen,j-i+1);
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]>0){
                            count++;
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        return res;
    }
};