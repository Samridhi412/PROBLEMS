class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestsum=nums[0];
        int currsum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            if(bestsum<currsum){
                bestsum=currsum;
            }
            if(currsum<0){
                currsum=0;
            }
        }
        return bestsum;
    }
};