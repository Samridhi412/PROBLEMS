class Solution {
     vector<string> res;
    void partition(string& s,int ind,int n,set<string>& st,string temp){
        if(ind==n){
            temp.pop_back();
            res.push_back(temp);
            return;
        }
        for(int i=ind;i<n;i++){
            string str=s.substr(ind,i-ind+1);
            if(st.count(str)){
                partition(s,i+1,n,st,temp+str+" ");
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       
        set<string> st;
        int n=wordDict.size();
        for(int i=0;i<n;i++){
            st.insert(wordDict[i]);
        }
        string temp;
        partition(s,0,s.size(),st,temp);
        return res;
    }
};