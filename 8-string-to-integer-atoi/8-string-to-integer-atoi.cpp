class Solution {
public:
    int myAtoi(string s) {
        int ans=0;
        int n=s.size();
        if(s=="-2147483647")return -1*INT_MAX;
        if(s=="-2147483648")return INT_MIN;
        bool isneg=0;
        int i=0;
            while(i<n&&s[i]==' '){
                // cout<<"a";
                i++;
            }
            if(i<n&&(s[i]=='-'||s[i]=='+')){
                // cout<<"h";
               isneg=(s[i]=='-')?1:0;
                i++;
            }
            while(i<n&&(0<=s[i]-'0'&&s[i]-'0'<=9)){
                if(ans>INT_MAX/10||(ans==INT_MAX/10&&s[i]-'0'>7)){
                    ans= INT_MAX;
                    break;
                }
                else if(ans<INT_MIN/10||(ans==INT_MIN/10&&s[i]-'0'<-8)){
                    ans= INT_MIN;
                    break;
                }
                ans=1LL*ans*10+s[i]-'0';
                // cout<<ans<<endl;
                i++;
            }
        if(isneg&&ans==INT_MAX)return INT_MIN;
        return (isneg==1)?-1*ans:ans;
    }
};