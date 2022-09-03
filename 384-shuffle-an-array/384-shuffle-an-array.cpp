class Solution {
public:
    vector<int> original,temp;
    
    Solution(vector<int>& nums) {
        original=nums;
        temp=nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        int n=temp.size();
        for(int i=n-1;i>0;i--){
            int j=rand()%(i+1);
            swap(temp[i],temp[j]);
        }
        return temp;
    }
};
// class Solution {
//     vector<int> nums,v;
// public:
//     Solution(vector<int>& nums1) {
//         this->nums=nums1;
//         this->v=nums1;
//     }
    
//     vector<int> reset() {
//         // nums=v;
//         return v;
//     }
    
//     vector<int> shuffle() {
//         int n=v.size();
//         int idx2=rand()%n;
//         static int i=0;
//         swap(nums[i%n],nums[idx2]);
//         i++;
//         return nums;
//     }
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */