class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto x:nums){
            pq.push(x);
        }
        int i=0;
        int ele=-1;
        while(i<k){
            ele=pq.top();
            pq.pop();
            i++;
        }
        return ele;
    }
};