class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool iscol=false;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
             if(j==0&&matrix[i][j]==0){
                 iscol=true;
                 matrix[i][0]=0;
                 continue;
             }  
                if(matrix[i][j]==0){
                matrix[0][j]=0;
                matrix[i][0]=0;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(j==0){
                    if(iscol){
                        matrix[i][j]=0;
                    }
                    continue;
                }
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
};