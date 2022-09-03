class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // unordered_map<int,int> mp;
        // for(int i=0;i<nums1.size();i++){
        //     mp[nums1[i]]++;
        // }
        vector<int> res;
        // for(int i=0;i<nums2.size();i++){
        //     unordered_map<int,int>::iterator it=mp.find(nums2[i]);
        //     if(it!=mp.end()&&it->second>0){
        //         res.push_back(nums2[i]);
        //         it->second--;
        //     }
        // }
        // return res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]==nums2[j]){
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return res;
    }
};