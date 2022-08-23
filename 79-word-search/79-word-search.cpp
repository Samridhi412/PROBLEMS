// int dx[4]={0,0,1,-1};
// int dy[4]={1,-1,0,0};
class Solution {
    void helper(vector<vector<char>>& board, vector<vector<bool>>& visit ,string& word,int ind,int i,int j,bool& flag){
        // cout<<i<<" "<<j<<endl;
        int n=board.size();
        int m=board[0].size();
        visit[i][j]=true;
        if(ind==word.size()){
            flag=1;
            return;
        }
       
        
        if(i > 0 && visit[i-1][j] == false && word[ind] == board[i-1][j]&&flag==false)
        {
            helper(board,visit,word,ind+1,i-1,j,flag);
        }

        if(j > 0 && visit[i][j-1] == false && word[ind] == board[i][j-1]&&flag==false)
        {
            helper(board,visit,word,ind+1,i,j-1,flag);
        }

        if(i < n-1 && visit[i+1][j] == false && word[ind] == board[i+1][j]&&flag==false)
        {
            helper(board,visit,word,ind+1,i+1,j,flag);
        }

        if(j < m-1 && visit[i][j+1] == false && word[ind] == board[i][j+1]&&flag==false)
        {
            helper(board,visit,word,ind+1,i,j+1,flag);
        }
        visit[i][j]=0;
        // return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<bool>> visit(n,vector<bool>(m,false));
                    bool flag=0;
                if(board[i][j]==word[0]){
                    helper(board,visit,word,1,i,j,flag);
                    }
                if(flag){
                        return true;
                        }
                }
        }
        return false;
    }
};





















// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string &word) 
//     {
//         // we will check for each cell, if this is the starting position
//         //then recursively check for its neighbours and if no matched we will do backtracking
//         //that's why we marked vis true initially when visiting the cell, but after visiting we marked it false.
        
//         int m = board.size();
//         int n = board[0].size();
        
//         for(int i = 0; i < m; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 //starting cell 
//                 vector<vector<bool>> vis(m+10, vector<bool>(n+10, 0));
//                 bool flag = 0;
                
//                 //checking for each cell
//                 if(board[i][j] == word[0])
//                 {
//                     match(board, word, vis, i, j, flag, 1);
//                 }
                
//                 if(flag == 1)
//                 {
//                     return true;
//                 }
//             }
//         }
        
//         return false;
//     }
    
//     void match(vector<vector<char>>& board, string &word, vector<vector<bool>> &vis, int r, int c, bool &flag, int ind)
//     {        
//         int m = board.size();
//         int n = board[0].size();
        
//         vis[r][c] = 1;
        
//         //base cases
//         if(ind == word.length())
//         {
//             flag = 1;
//             return;
//         }
        
        
//         //4 directions to be checked
//         if(r > 0 && vis[r-1][c] == false && word[ind] == board[r-1][c] && flag == 0)
//         {
//             match(board, word, vis, r-1, c, flag, ind+1);
//         }

//         if(c > 0 && vis[r][c-1] == false && word[ind] == board[r][c-1] && flag == 0)
//         {
//             match(board, word, vis, r, c-1, flag, ind+1);
//         }

//         if(r < m-1 && vis[r+1][c] == false && word[ind] == board[r+1][c] && flag == 0)
//         {
//             match(board, word, vis, r+1, c, flag, ind+1);
//         }

//         if(c < n-1 && vis[r][c+1] == false && word[ind] == board[r][c+1])
//         {
//             match(board, word, vis, r, c+1, flag, ind+1);
//         }
        
//         vis[r][c] = 0;

//     }
// };