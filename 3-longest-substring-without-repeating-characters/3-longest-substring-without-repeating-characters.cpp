class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
         int n=s.size();
        if(n==0||n==1)return n;
       unordered_map<char,int> mp;
        int maxi=-1e9;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()==j-i+1){
                maxi=max(maxi,j-i+1);
            }
            else if(mp.size()<j-i+1){
                while(i<j&&mp.size()<j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                if(mp.size()==j-i+1){
                    maxi=max(maxi,j-i+1);
                }
            }
            j++;
        }
        return maxi;
    }
};