class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        while(i<n){
            int l=i+1,j=n-1;
            while(l<j){
               if((nums[l]+nums[j]+nums[i])==0){
                   res.push_back({nums[i],nums[l],nums[j]});
                    int vl=nums[l];
                    int vj=nums[j];
                    while(l<j&&nums[l]==vl)l++;
                    while(j>l&&nums[j]==vj)j--;
               }
                else if((nums[l]+nums[j]+nums[i])>0){
                    j--;
                }
                else{
                    l++;
                }
               
            }
            int vi=nums[i];
            while(i<n&&nums[i]==vi)i++;
        }
        return res;
    }
};