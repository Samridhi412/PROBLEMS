class Solution {
public:
    int calculate(string s) {
        int len=s.size();
        if(len==0)return 0;
        stack<int> st;
        int curr=0;
        char operation='+';
        for(int i=0;i<len;i++){
            if(isdigit(s[i])){
                curr=curr*10+(s[i]-'0');
            }
            if(!isdigit(s[i])&&!iswspace(s[i])||i==len-1){
                if(operation=='+'){
                    st.push(curr);
                }
                else if(operation=='-'){
                    st.push(-curr);
                }
                else if(operation=='*'){
                    int ele=st.top();
                    st.pop();
                    st.push(ele*curr);
                }
                else if(operation=='/'){
                    int ele=st.top();
                    st.pop();
                    st.push(ele/curr);
                }
                operation=s[i];
                curr=0;
            }
        }
        int res=0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};