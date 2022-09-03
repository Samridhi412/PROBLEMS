class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]++;
        }
        vector<int> res;
        for(int i=0;i<nums2.size();i++){
            unordered_map<int,int>::iterator it=mp.find(nums2[i]);
            if(it!=mp.end()&&it->second>0){
                res.push_back(nums2[i]);
                it->second--;
            }
        }
        return res;
    }
};