class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxi=-1e9;
        // vector<int> left(n),right(n);
        int left,right;
        for(int i=0;i<n;i++){
            int l=0,r=n-1;
            left=i,right=i;
            while(l<i){
                if(height[l]>=height[i]){
                    left=l;
                    break;
                }
                l++;
            }
            while(r>i){
                if(height[r]>=height[i]){
                    right=r;
                    break;
                }
                r--;
            }
            maxi=max(maxi,height[i]*(right-left));
        }
        return maxi;
    }
};