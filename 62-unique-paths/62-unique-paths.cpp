class Solution {
    void helper(int i,int j,int n,int m,string temp,vector<string>& res){
        if(i>n||j>m){
            return;
        }
        if(i==n&&j==m){
            res.push_back(temp);
            return;
        }
        helper(i,j+1,n,m,temp+"R",res);
        helper(i+1,j,n,m,temp+"D",res);
        
    }
public:
    int uniquePaths(int m, int n) {
        // vector<string> res;
        // string temp;
        // helper(0,0,m-1,n-1,temp,res);
        // for(int i=0;i<res.size();i++){
        //     cout<<res[i]<<endl;
        // }
        // return res.size();
        int N=m+n-2;
        int R=m-1;
        unsigned long long int ans=1;
        for(int i=1;i<=R;i++){
            ans*=(N-R+i);
            ans/=i;
        }
        return ans;
    }
};