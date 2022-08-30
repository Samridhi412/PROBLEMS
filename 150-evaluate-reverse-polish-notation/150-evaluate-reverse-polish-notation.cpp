class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int op1=s.top();
                s.pop();
                int op2=s.top();
                s.pop();
                if(tokens[i]=="+")s.push(op1+op2);
                else if(tokens[i]=="-")s.push(op2-op1);
                else if(tokens[i]=="*")s.push(op1*op2);
                else if(tokens[i]=="/")s.push(op2/op1);
            }
            else{
                int n=stoi(tokens[i]);
                s.push(n);
            }
        }
        return s.top();
    }
};