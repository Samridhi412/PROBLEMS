#include<bits/stdc++.h>
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int maxpoints=INT_MIN;
        int curmax=0,verticalpoints=0,overlapping=0;
        map<pair<int,int>,int> slope_count;
        for(int i=0;i<n;i++){
            curmax=0,verticalpoints=0,overlapping=0;
            for(int j=i+1;j<n;j++){
                if(points[i]==points[j]){
                    overlapping++;
                }
                else if(points[i][0]==points[j][0]){
                    verticalpoints++;
                }
                else{
                    int num=points[j][1]-points[i][1];
                    int den=points[j][0]-points[i][0];
                    int g=__gcd(num,den);
                    num/=g;
                    den/=g;
                    slope_count[{num,den}]++;
                    curmax=max(curmax,slope_count[{num,den}]);
                }
                curmax=max(curmax,verticalpoints);
            }
            maxpoints=max(maxpoints,curmax+overlapping+1);
            slope_count.clear();
        }
        return maxpoints;
    }
};