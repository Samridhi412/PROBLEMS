class Solution {
    void helper(vector<int>& nums,int target,vector<int>& res,int low,int high){
        // cout<<low<<" "<<high<<endl;
         while(low<=high){
            int mid=(low+high)>>1;
            if(nums[mid]==target){
                if(res[0]==-1||res[0]>mid){
                    res[0]=mid;
                }
                if(res[1]==-1||res[1]<mid){
                    res[1]=mid;
                }
                // cout<<res[0]<<" "<<res[1]<<endl;
                helper(nums,target,res,low,mid-1);
                helper(nums,target,res,mid+1,high);
                return;
                
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        int n=nums.size();
       helper(nums,target,res,0,n-1);
        return res;
    }
};