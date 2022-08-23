// int dx[4]={0,0,1,-1};
// int dy[4]={1,-1,0,0};
// class Solution {
//     bool helper(vector<vector<char>>& board, vector<vector<bool>> visit ,string& word,int ind,int i,int j){
//         // cout<<i<<" "<<j<<endl;
//         if(ind==word.size()){
//             return true;
//         }
       
//         visit[i][j]=true;
//         for(int k=0;k<4;k++){
//              if(i+dx[k]<0||i+dx[k]>=board.size()||j+dy[k]<0||j+dy[k]>=board[0].size()||visit[i+dx[k]][j+dy[k]]){
//                          continue;
//                  }
//             if(board[i+dx[k]][j+dy[k]]==word[ind]){
//                 if(helper(board,visit,word,ind+1,i+dx[k],j+dy[k])){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         int n=board.size();
//         int m=board[0].size();
//         vector<vector<bool>> visit(n,vector<bool>(m,false));
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(board[i][j]==word[0]){
//                     if(helper(board,visit,word,1,i,j)){
//                         return true;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };





















class Solution {
public:
    bool exist(vector<vector<char>>& board, string &word) 
    {
        // we will check for each cell, if this is the starting position
        //then recursively check for its neighbours and if no matched we will do backtracking
        //that's why we marked vis true initially when visiting the cell, but after visiting we marked it false.
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                //starting cell 
                vector<vector<bool>> vis(m+10, vector<bool>(n+10, 0));
                bool flag = 0;
                
                //checking for each cell
                if(board[i][j] == word[0])
                {
                    match(board, word, vis, i, j, flag, 1);
                }
                
                if(flag == 1)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    void match(vector<vector<char>>& board, string &word, vector<vector<bool>> &vis, int r, int c, bool &flag, int ind)
    {        
        int m = board.size();
        int n = board[0].size();
        
        vis[r][c] = 1;
        
        //base cases
        if(ind == word.length())
        {
            flag = 1;
            return;
        }
        
        
        //4 directions to be checked
        if(r > 0 && vis[r-1][c] == false && word[ind] == board[r-1][c] && flag == 0)
        {
            match(board, word, vis, r-1, c, flag, ind+1);
        }

        if(c > 0 && vis[r][c-1] == false && word[ind] == board[r][c-1] && flag == 0)
        {
            match(board, word, vis, r, c-1, flag, ind+1);
        }

        if(r < m-1 && vis[r+1][c] == false && word[ind] == board[r+1][c] && flag == 0)
        {
            match(board, word, vis, r+1, c, flag, ind+1);
        }

        if(c < n-1 && vis[r][c+1] == false && word[ind] == board[r][c+1])
        {
            match(board, word, vis, r, c+1, flag, ind+1);
        }
        
        vis[r][c] = 0;

    }
};