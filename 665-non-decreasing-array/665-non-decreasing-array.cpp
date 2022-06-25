class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool ret = true;
        int count = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[i-1]){
                count++;
               
                if(i-2 < 0 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];                     // Just to keep right track.
                else
                    nums[i] = nums[i-1];            // to keep array increasing
            }
            if(count > 1) return false;
        }
        if(count > 1) ret = false;
        return ret;
    }
};