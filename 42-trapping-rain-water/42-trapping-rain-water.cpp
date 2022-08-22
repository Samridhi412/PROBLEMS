class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int leftmax=0,rightmax=0;
        int tot=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(leftmax<height[l]){
                    leftmax=height[l];
                       }
                else{
                    tot+=leftmax-height[l];
                }
                l++;
        }
            else{
                if(rightmax<height[r]){
                    rightmax=height[r];
                }
                else{
                    tot+=rightmax-height[r];
                }
                r--;
            }
    }
        return tot;
}
};