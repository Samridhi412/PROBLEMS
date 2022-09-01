class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        int flag=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                flag++;
                continue;
            }
            prod*=nums[i];
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(flag==1){
                if(nums[i]==0){
                    res.push_back(prod);
                }
                else{
                    res.push_back(0);
                }
            }
            else if(flag>1){
                res.push_back(0);
            }
            else{
                res.push_back(prod/nums[i]);
            }
        }
        return res;
    }
};