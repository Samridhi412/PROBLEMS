class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int res;
        for(int i=0;i<n;i++){
            int cur=abs(nums[i]);
            if(nums[cur]<0){
                res= cur;
                break;
            }
            nums[cur]*=-1;
        }
        return res;
    }
};