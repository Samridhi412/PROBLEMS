class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
       int n=words.size();
        unordered_set<string> hashset;
        for(auto x:words){
            hashset.insert(x);
        }
        for(int i=0;i<n;i++){
            for(int k=1;k<words[i].size();k++){
                hashset.erase(words[i].substr(k));
            }
        }
        int total_len=0;
        for(auto str:hashset){
            total_len+=str.size()+1;
        }
        return total_len;
    }
};