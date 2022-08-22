class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> row(9),col(9),boxes(9);
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.')continue;
                if(row[i].count(board[i][j])){
                    return false;
                }
                if(col[j].count(board[i][j])){
                    return false;
                }
                if(boxes[3* (i/3) + (j/3) % 3].count(board[i][j])){
                    return false;
                }
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                boxes[3*(i/3) + (j/3)%3].insert(board[i][j]);
            }
            
        }
        return true;
    }
};