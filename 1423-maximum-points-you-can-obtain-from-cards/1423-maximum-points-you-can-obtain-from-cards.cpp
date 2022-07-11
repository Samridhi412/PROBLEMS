class Solution {
    vector<int> psum;
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        psum.push_back(0);
        psum.push_back(cardPoints[0]);
        for(int i=1;i<n;i++){
            psum.push_back(*psum.rbegin()+cardPoints[i]);
        }
        int ans=INT_MIN;
        int k1=k;
        while(k1){
            int rsum=*psum.rbegin()-psum[n-k1];
            int lsum=psum[k-k1];
            ans=max(ans,lsum+rsum);
            k1--;
        }
        ans=max(ans,psum[k]);
        return ans;
    }
};