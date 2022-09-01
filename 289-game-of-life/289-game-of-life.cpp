class Solution {
    int dx[8]={0,0,1,-1,-1,1,-1,1};
    int dy[8]={1,-1,0,0,-1,1,1,-1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int nozeros=0,noones=0;
                for(int k=0;k<8;k++){
                    int n_i=i+dx[k];
                    int n_j=j+dy[k];
                    if(n_i>=0&&n_i<n&&n_j>=0&&n_j<m){
                        if(board[n_i][n_j]==0||board[n_i][n_j]==-2)nozeros++;
                        else noones++;
                    }
                }
                if(board[i][j]==0){
                    if(noones==3){
                        board[i][j]=-2;
                    }
                }
                else{
                    if(noones<2||noones>3){
                        board[i][j]=-1;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==-2){
                    board[i][j]=1;
                }
                else if(board[i][j]==-1){
                    board[i][j]=0;
                }
            }
        }
    }
};