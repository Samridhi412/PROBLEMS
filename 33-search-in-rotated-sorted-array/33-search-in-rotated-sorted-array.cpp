class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)return -1;
        if(n==1&&nums[0]==target)return 0;
        else if(n==1&&nums[0]!=target)return -1;
        else if(n==2){
            if(nums[0]==target)return 0;
            else if(nums[1]==target)return 1;
            else return -1;
        }
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)>>1;
            
            // cout<<mid<<endl;
            if(nums[mid]==target){
                return mid;
            }
            else if((mid-1>=0&&nums[mid-1]>nums[mid])&&(mid+1<n&&nums[mid+1]>nums[mid])){
                if(target<nums[0]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else if(nums[mid]<nums[0]){
                if(target>nums[mid]&&target<nums[0]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else if(nums[mid]>=nums[0]){
                if(target>=nums[0]&&target<nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return -1;
    }
};