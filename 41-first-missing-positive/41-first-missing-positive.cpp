class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // unordered_map<int,int> mp;
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     mp[nums[i]]++;
        // }
        // int z=1;
        // while(1){
        //     if(mp.find(z)==mp.end()){
        //         break;
        //     }
        //     else{
        //         z++;
        //     }
        // }
        // return z;
        
        for(int i=0;i<n;i++){
            if(nums[i]<1||nums[i]>n){
                nums[i]=0;
            }
        }
        nums.push_back(0);
        for(int i=0;i<=n;i++){
            while(nums[nums[i]]!=nums[i]){
                swap(nums[nums[i]],nums[i]);
            }
        }
        int ans=n+1;
        for(int i=1;i<=n;i++){
            if(i!=nums[i]){
                ans= i;
                break;
            }
        }
        return ans;
    }
};