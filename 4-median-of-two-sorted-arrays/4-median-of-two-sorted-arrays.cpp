class Solution {
    double median(vector<int> v){
        int n=v.size();
        return (n%2)?v[n/2]*1.0:(v[n/2] + v[n/2 -1])/2.0;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2)return findMedianSortedArrays(nums2,nums1);
         if(n1==0)return median(nums2);
        int low=0;
        int high=n1;
        int tot=(n1+n2+1)/2;
        while(low<=high){
            int mid=(low+high)/2;
            int len2=tot-mid;
            int fleft=mid==0?INT_MIN:nums1[mid-1];
            int fright=mid==n1?INT_MAX:nums1[mid];
            int sleft=len2==0?INT_MIN:nums2[len2-1];
            int sright=len2==n2?INT_MAX:nums2[len2];
            if(fleft<=sright&&sleft<=fright){
                if((n1+n2)%2){
                    return 1.0*max(fleft,sleft);
                }
                else{
                    return (1.0*max(fleft,sleft)+min(fright,sright))/2.0;
                }
            }
            else if(fleft>sright){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        return 0.0;
    }
};