class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = (int)board.size();
        int m = (int)board[0].size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (board[i][j] == 'O') {
                        dfs(i, j, board, n, m);
                    }
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '-') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dfs(int r, int c, vector<vector<char>>& board, int n, int m) {
        if (r < 0 || r >= n || c < 0 || c >= m || board[r][c] != 'O') return;
        
        board[r][c] = '-';
        
        dfs(r - 1, c, board, n, m);
        dfs(r, c + 1, board, n, m);
        dfs(r + 1, c, board, n, m);
        dfs(r, c - 1, board, n, m);
    }
};