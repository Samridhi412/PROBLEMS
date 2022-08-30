class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxprod=INT_MIN;
        int prod=1;
        for(int i=0;i<n;i++){
            prod*=nums[i];
            maxprod=max(maxprod,prod);
            if(nums[i]==0){
                prod=1;
                continue;
            }
            
            
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            prod*=nums[i];
            maxprod=max(maxprod,prod);
            if(nums[i]==0){
                prod=1;
                continue;
            }
            
        }
        return maxprod;
    }
};