class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int maxlen=INT_MIN;
        for(int i=0;i<n;i++){
            if(s.count(nums[i]-1))continue;
            int currele=nums[i];
            int len=1;
            while(s.count(currele+1)){
                currele=currele+1;
                len++;
            }
            maxlen=max(maxlen,len);
        }
        return max(0,maxlen);
    }
};