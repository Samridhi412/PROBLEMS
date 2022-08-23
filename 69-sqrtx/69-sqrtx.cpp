class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1){
            return x;
        }
        int low=0;
        int high=x;
        int ans=0;
        while(low<=high){
            int mid=(low+high)>>1;
            long long val=1LL*mid*mid;
            if(val==x){
                ans=mid;
                break;
            }
            else if(val<x){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};