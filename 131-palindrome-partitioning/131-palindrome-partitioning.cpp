class Solution {
    bool ispal(string& s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void front_partition(string& s,int ind,vector<string>& temp,vector<vector<string>>& res,int n){
        if(ind==n){
            res.push_back(temp);
            return;
        }
        for(int i=ind;i<n;i++){
            if(ispal(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                front_partition(s,i+1,temp,res,n);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        front_partition(s,0,temp,res,s.size());
        return res;
    }
};