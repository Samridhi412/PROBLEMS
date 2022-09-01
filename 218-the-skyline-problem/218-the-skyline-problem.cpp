// class Solution {
// public:
//     vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
//         vector<vector<int>> points;
//         int n=buildings.size();
//         for(int i=0;i<n;i++){
//             points.push_back({buildings[i][0],-buildings[i][1]});
//             points.push_back({buildings[i][0],buildings[i][1]});
//         }
//         sort(points.begin(),points.end());
//         vector<vector<int>> res;
//         int m=points.size();
//         int curheight;
//         priority_queue<int> pq;
//         for(int i=0;i<m;i++){
//             if(points[i][1]<0){
//                 pq.push(points[i][1]);
//             }
//             else{
//                 auto it=pq.find(points[i][1]);
//                 pq.remove(it);
//             }
//             int mxheight=pq.top();
//             if(mxheight!=curheight){
//                 res.push_back({points[i][0],mxheight});
//                 curheight=mxheight;
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        int n = buildings.size();
        vector<pair<int,int>>wall;
        int left = 0,right =0,height=0;
        for(int i=0;i<n;i++)
        {
            left = buildings[i][0];
            right = buildings[i][1];
            height = buildings[i][2];
            wall.push_back({left,-height});
            wall.push_back({right,height});  
        }
        sort(wall.begin(),wall.end());
        multiset<int>pq{0};
        int ht = 0;
        vector<vector<int>>ans;
        for(auto x:wall)
        {
            cout<<x.first<<" "<<x.second<<" ";
        }
       for(int i=0;i<wall.size();i++)
       {
           int maxht = wall[i].second;
           if(maxht<0)
           {
               pq.insert(-maxht);
           }
           else
           {
               pq.erase(pq.find(maxht));
           }
           if(*pq.rbegin()!=ht)
           {
               ht = *pq.rbegin();
               ans.push_back({wall[i].first,ht});
           }
       }
        return ans;
        
    }
};