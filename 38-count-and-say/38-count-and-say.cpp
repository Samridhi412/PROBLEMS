class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string s="1";
        string news="";
        for(int i=2;i<=n;i++){
            s=s+'$';
            int count=1;
            int j=1;
            // char ch=s[j];
            while(j<s.size()){
                if(s[j]==s[j-1]){
                    count++;
                }
                else{
                    news=news+to_string(count)+s[j-1];
                    count=1;
                }
                j++;
            }
            s=news;
            news="";
        }
        return s;
    }
};