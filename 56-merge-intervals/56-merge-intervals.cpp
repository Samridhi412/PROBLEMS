class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int n=intervals.size();
        for(int i=1;i<n;i++){
            int st=res.back()[0];
            int en=res.back()[1];
            if(intervals[i][0]<=en){
                res.back()[1]=max(intervals[i][1],en);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};