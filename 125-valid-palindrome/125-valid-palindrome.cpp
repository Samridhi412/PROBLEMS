class Solution {
    bool isalphanum(char ch){
        if((ch>=97&&ch<=122)||(ch>=48&&ch<=57))return true;
        return false;
    }
    void islower(string& s){
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]>='A'&&s[i]<='Z'){
                s[i]=s[i]-'A'+'a';
            }
        }
    }
public:
    bool isPalindrome(string s) {
        islower(s);
        int l=0;
        int r=s.size()-1;
        while(l<=r){
            if(!isalphanum(s[l])){l++; continue;}
            if(!isalphanum(s[r])){r--; continue;}
            // if(r>=l)return true;
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};