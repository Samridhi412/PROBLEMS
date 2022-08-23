class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string s=strs[i];
            sort(strs[i].begin(),strs[i].end());
                mp[strs[i]].push_back(s);
        }
        vector<vector<string>> res;
        for(auto x:mp){
            res.push_back(x.second);
        }
        return res;
    }
};