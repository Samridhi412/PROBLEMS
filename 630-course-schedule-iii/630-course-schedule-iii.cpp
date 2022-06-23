class Solution {
    int schedule(vector<vector<int>>& courses,int index,int time,vector<vector<int>>& dp){
        if(index==courses.size()){
            return 0;
        }
        if(dp[index][time]!=-1)return dp[index][time];
        int ans=INT_MIN;
        if(time+courses[index][0]<=courses[index][1]){
            ans=max(ans,schedule(courses,index+1,time+courses[index][0],dp)+1);
        }
        return dp[index][time]=max(ans,schedule(courses,index+1,time,dp));
    }
    static bool cmp(vector<int>& a,vector<int>& b){
       return a[1]<b[1];
   }
public:
    
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
    // int maxi=INT_MIN;
       sort(courses.begin(),courses.end(),cmp);
        // vector<vector<int>> dp(n,vector<int>(courses[n-1][1]+1,-1));
        // return schedule(courses,0,0,dp);
        int time=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            if(courses[i][0]+time<=courses[i][1]){
                pq.push(courses[i][0]);
                time+=courses[i][0];
            }
            else{
                if(!pq.empty()&&pq.top()>courses[i][0]){
                    int maxi=pq.top();
                    pq.pop();
                    pq.push(courses[i][0]);
                    time=time+courses[i][0]-maxi;
                }
            }
        }
        return pq.size();
    }
};