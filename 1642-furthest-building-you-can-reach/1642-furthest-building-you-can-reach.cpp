class Solution {
     int furthestBuilding(vector<int>& heights, int bricks, int ladders,int index,int n) {
        // if(bricks==0&&ladders==0)return index;
        if(index==n-1)return index;
        if(heights[index+1]>heights[index]){
            int a=INT_MIN,b=INT_MIN;
           if(ladders>0)a=furthestBuilding(heights,bricks,ladders-1,index+1,n);
        if(bricks-(heights[index+1]-heights[index])>=0)b=furthestBuilding(heights,bricks-(heights[index+1]-heights[index]),ladders,index+1,n);
            return max(a,max(b,index));
        }
         return furthestBuilding(heights,bricks,ladders,index+1,n);
    }
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        long long n=heights.size();
        // // return furthestBuilding(heights,bricks,ladders,0,n);
        // vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(ladders+1,vector<long long>(bricks+1,0)));
        // for(long long j=0;j<=ladders;j++){
        //     for(long long k=0;k<=bricks;k++){
        //         dp[n-1][j][k]=n-1;
        //     }
        // }
        // for(long long ind=n-2;ind>=0;ind--){
        //     for(long long j=0;j<=ladders;j++){
        //         for(long long k=0;k<=bricks;k++){
        //             if(heights[ind+1]>heights[ind]){
        //                  long long a=INT_MIN,b=INT_MIN;
        //    if(j>0)a=dp[ind+1][j-1][k];
        // if(k-(heights[ind+1]-heights[ind])>=0)b=dp[ind+1][j][k-(heights[ind+1]-heights[ind])];
        //     dp[ind][j][k]= max(a,max(b,ind));
        //             }
        //             else{
        //                 dp[ind][j][k]=dp[ind+1][j][k];
        //             }
        //         }
        //     }
        // }
        // return dp[0][ladders][bricks];
        priority_queue<int,vector<int>,greater<int>> min_heap;
        for(int i=1;i<n;i++){
            if(heights[i]<=heights[i-1])continue;
            min_heap.push(heights[i]-heights[i-1]);
            if(min_heap.size()>ladders){
                bricks-=min_heap.top();
                min_heap.pop();
                if(bricks<0)return i-1;
            }
        }
        return n-1;
    }
};