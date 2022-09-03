typedef pair<int,int> pii;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //priority_queue
        int n=matrix.size();
        if(k<2)return matrix[0][0];
        if(k>n*n)return -1;
        
        
//         auto cmp=[&](pii& a,pii& b){
//              return matrix[a.first][a.second]>matrix[b.first][b.second];
//         };
//         priority_queue<pii,vector<pii>,decltype(cmp)> pq(cmp);
//         for(int i=0;i<n;i++){
//         pq.push({i,0});
//         }
//         for(int i=1;i<k;i++){
//         pii f=pq.top();
//         pq.pop();
//         if(f.second+1<n)pq.push({f.first,f.second+1});
//         }
//         return matrix[pq.top().first][pq.top().second];
        
        //BINARY SEARCH
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        while(low<=high){
            int mid=(low+high)>>1;
            int ans=0;
            for(int i=0;i<n;i++){
                int pos=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
                ans+=pos;
                
            }
            if(ans<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};