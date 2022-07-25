class Solution {
    bool possible(int mid,vector<string>& strs,int index){
        string res=strs[0].substr(0,mid);
        for(auto x:strs){
            if(x.substr(0,mid)!=res){
                return false;
            }
        }
        return true;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0)return "";
        if(n==1)return strs[0];
        // string res="";
        int minlen=205;
        int index=-1;
        for(int i=0;i<n;i++){
            if(strs[i].size()<minlen){
                minlen=strs[i].size();
                // res=strs[i];
                index=i;
            }
        }
        if(minlen==0)return "";
        int low=1;
        int high=minlen;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(mid,strs,index)){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        // cout<<ans<<" "<<res<<endl;
        return ans==0?"":strs[0].substr(0,ans);
    }
};