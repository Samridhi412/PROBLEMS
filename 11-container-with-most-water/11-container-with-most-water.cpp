class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxi=-1e9;
        // vector<int> left(n),right(n);
        // int left,right;
        // for(int i=0;i<n;i++){
            int i=0,j=n-1;
        //     left=i,right=i;
        //     while(l<i){
        //         if(height[l]>=height[i]){
        //             left=l;
        //             break;
        //         }
        //         l++;
        //     }
        //     while(r>i){
        //         if(height[r]>=height[i]){
        //             right=r;
        //             break;
        //         }
        //         r--;
        //     }
        //     maxi=max(maxi,height[i]*(right-left));
        // }
        while(i<j){
            maxi=max(maxi,(j-i)*min(height[i],height[j]));
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxi;
    }
};