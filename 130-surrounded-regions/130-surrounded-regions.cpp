class Solution {
    int dx[4]={0,0,-1,+1};
    int dy[4]={+1,-1,0,0};
    void dfs(int i,int j,int nrow,int ncol,vector<vector<char>>& board){
        board[i][j]='-';
        for(int k=0;k<4;k++){
            int row=i+dx[k];
            int col=j+dy[k];
            if(row>=0&&row<nrow&&col>=0&&col<ncol&&board[row][col]=='O'){
                dfs(row,col,nrow,ncol,board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            int j=0;
            if(board[i][j]=='O'){
                dfs(i,j,n,m,board);
            }
            j=m-1;
            if(board[i][j]=='O'){
                dfs(i,j,n,m,board);
            }
        }
        for(int j=0;j<m;j++){
            int i=0;
            if(board[i][j]=='O'){
                dfs(i,j,n,m,board);
            }
            i=n-1;
            if(board[i][j]=='O'){
                dfs(i,j,n,m,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='-'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};