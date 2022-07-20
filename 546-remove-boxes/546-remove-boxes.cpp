int dp[102][102][102];
class Solution {
    int solve( vector<pair<int,int>>& groups,int i, int j, int extra){
        if(i>j)return 0;
        if(dp[i][j][extra]!=-1)return dp[i][j][extra];
        int answer=(groups[i].second+extra)*(groups[i].second+extra)+solve(groups,i+1,j,0);
        for(int group=i+2;group<=j;group++){
            if(groups[group].first==groups[i].first){
                answer=max(answer,solve(groups,i+1,group-1,0)+solve(groups,group,j,extra+groups[i].second));
            }
        }
        return dp[i][j][extra]=answer;
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        memset(dp,-1,sizeof(dp));
        vector<pair<int,int>> groups;
        int count=0;
        int i=0;
        int val;
        while(i<n){
            if(i==0){
                count++;
                val=boxes[i];
            }
            else{
                if(boxes[i]==boxes[i-1]){
                    count++;
                }
                else{
                    groups.push_back({val,count});
                    count=1;
                    val=boxes[i];
                }
            }
            i++;
        }
        groups.push_back({val,count});
        return solve(groups,0,groups.size()-1,0);
    }
};