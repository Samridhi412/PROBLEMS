typedef pair<int,int> pii;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> res;
        for(auto it:nums){
            mp[it]++;
        }
        auto cmp=[&](pii& a,pii& b){
            return a.first<b.first;
        };
        priority_queue<pii> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        for(int i=1;i<=k;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};