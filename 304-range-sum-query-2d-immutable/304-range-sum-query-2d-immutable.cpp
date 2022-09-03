class NumMatrix {
    vector<vector<int>> auxi;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        auxi.resize(n,vector<int>(m));
        auxi[0][0]=matrix[0][0];
        for(int i=1;i<m;i++){
            auxi[0][i]=auxi[0][i-1]+matrix[0][i];
        }
        for(int i=1;i<n;i++){
            auxi[i][0]=auxi[i-1][0]+matrix[i][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                auxi[i][j]=auxi[i-1][j]+auxi[i][j-1]-auxi[i-1][j-1]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res=auxi[row2][col2];
        if(row1>0){
            res-=auxi[row1-1][col2];
        }
        if(col1>0){
            res-=auxi[row2][col1-1];
        }
        if(row1>0&&col1>0){
            res+=auxi[row1-1][col1-1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

//prefix sum---> sumof above and left area.