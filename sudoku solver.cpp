bool valid(vector<vector<int>> &board,int r,int c,int k){
      for(int i=0;i<9;i++){
          if(board[i][c]==k){
              return false;
          }
          if(board[r][i]==k){
              return false;
          }
          if(board[3*r/3+i/3][3*c/3+i%3]==k){
              return false;
          }
      }
      return true;
  }
bool solve(vector<vector<int>> &board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                for(int k=1;k<=9;k++){
                    board[i][j]=k;
                    if(valid(board,i,j,k)){
                        if(solve(board)){
                            return true;
                        }
                        board[i][j]=0;
                    }
                }
                 return false;
            }
        }
    }
}


vector << vector<int> > solveSudoku(vector<vector<int>> &board) {
    solve(board);
    return board;
}
  
