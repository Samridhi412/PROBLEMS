class Solution {
 bool isvalid(int arr[],int k){
     int cnt=0,cntk=0;
     for(int i=0;i<26;i++){
         if(arr[i]!=0){
             cnt++;
         }
         if(arr[i]>=k){
             cntk++;
         }
     }
     return cnt==cntk;
 }
public:
    int longestSubstring(string s, int k) {
        //BRITE FORCE
        int n=s.size();
        int maxlen=0;
        if(n<k||n==0)return 0;
        int count_chars[26]={0};
        for(int i=0;i<n;i++){
            memset(count_chars,0,sizeof(count_chars));
            for(int j=i;j<n;j++){
                count_chars[s[j]-'a']++;
                if(isvalid(count_chars,k)){
                    maxlen=max(maxlen,j-i+1);
                }
            }
        }
        return maxlen;
    }
};