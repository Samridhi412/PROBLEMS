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
    int helper(string& s,int k,int start,int end){
        int count[26]={0};
        for(int i=start;i<end;i++){
            count[s[i]-'a']++;
        }
        int left,right;
        for(int i=start;i<end;i++){
            if(count[s[i]-'a']<k){
                left=helper(s,k,start,i);
                right=helper(s,k,i+1,end);
                return max(left,right);
            }
            
        }
        return end-start;
    }
    int getuniquecount(string& s){
        bool mp[26];
        memset(mp,0,sizeof(mp));
        int uniq=0;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]-'a']==0){
                uniq++;
                mp[s[i]-'a']=1;
            }
            
        }
        return uniq;
    }
public:
    int longestSubstring(string s, int k) {
        //BRITE FORCE
        int n=s.size();
        int maxlen=0;
        if(n<k||n==0)return 0;
        // int count_chars[26]={0};
        // for(int i=0;i<n;i++){
        //     memset(count_chars,0,sizeof(count_chars));
        //     for(int j=i;j<n;j++){
        //         count_chars[s[j]-'a']++;
        //         if(isvalid(count_chars,k)){
        //             maxlen=max(maxlen,j-i+1);
        //         }
        //     }
        // }
        // return maxlen;
        
        
        
        //DIVIDE AND CONQUER
        // return helper(s,k,0,n);
        
        //sliding window
        int maxunique=getuniquecount(s);
        // cout<<maxunique<<endl;
        int count[26];
        for(int curruniq=1;curruniq<=maxunique;curruniq++){
            memset(count,0,sizeof(count));
            int startwindow=0,endwindow=0;
            int uniq=0,cntk=0;
            while(endwindow<n){
                if(uniq<=curruniq){
                    int idx=s[endwindow]-'a';
                    if(count[idx]==0){
                        uniq++;
                    }
                    count[idx]++;
                    if(count[idx]==k){
                        cntk++;
                    }
                    endwindow++;
                }
                else{
                    int idx=s[startwindow]-'a';
                    if(count[idx]==k){
                        cntk--;
                    }
                    count[idx]--;
                    if(count[idx]==0){
                        uniq--;
                    }
                    startwindow++;
                }
                if(uniq==curruniq&&uniq==cntk){
                    maxlen=max(maxlen,endwindow-startwindow);
                }
            }
        }
        return maxlen;
    }
};