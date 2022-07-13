class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2)return findMedianSortedArrays(nums2,nums1);
        int low=0;
        int high=n1;
        double ans;
        while(low<=high){
            int cnt1=(low+high)>>1;
            int total_left=(n1+n2)&1?(n1+n2+1)/2:(n1+n2)/2;
            int cnt2=total_left-cnt1;
            int l1=cnt1==0?INT_MIN:nums1[cnt1-1];
            int l2=cnt2==0?INT_MIN:nums2[cnt2-1];
            int r1=cnt1==n1?INT_MAX:nums1[cnt1];
            int r2=cnt2==n2?INT_MAX:nums2[cnt2];
            if(l1<=r2&&l2<=r1){
                if((n1+n2)&1){
                    ans=max(l1,l2);
                }
                else{
                    ans=(max(l1,l2)+min(r1,r2))/2.0;
                }
                break;
            }
            else if(l1>r2){
                high=cnt1-1;
            }
            else{
                low=cnt1+1;
            }
        }
        return ans;
    }
};