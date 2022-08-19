class Solution {
    bool isvalid(string temp){
        int bal=0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]=='(')bal++;
            else bal--;
            if(bal<0)return false;
        }
        return bal==0;
    }
    void add_parenthesis(string& temp,vector<string>& res,int ind,int m){
        if(ind==2*m){
            if(isvalid(temp)){
                res.push_back(temp);
            }
            return;
        }
        temp[ind]='(';
        add_parenthesis(temp,res,ind+1,m);
        temp[ind]=')';
        add_parenthesis(temp,res,ind+1,m);
    }
    void optimal(string& temp,vector<string>& res,int open,int close,int ind,int n){
        if(ind==2*n){
            res.push_back(temp);
            return;
        }
        if(open<n){
            temp[ind]='(';
            optimal(temp,res,open+1,close,ind+1,n);
        }
        if(close<open){
            temp[ind]=')';
            optimal(temp,res,open,close+1,ind+1,n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp(2*n,'.');
        // add_parenthesis(temp,res,0,n);
        optimal(temp,res,0,0,0,n);
        return res;
    }
};