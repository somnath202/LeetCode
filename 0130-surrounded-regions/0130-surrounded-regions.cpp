class Solution {
    void dfs(int r , int c , vector<vector<char>>&board , vector<vector<int>>& vis,int delrow[] , int delcol[]){
        vis[r][c] = 1 ;
        int n = board.size() , m = board[0].size();
        for(int i = 0 ; i < 4 ; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if(nrow >= 0 && nrow < n  && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O'){
                dfs(nrow,ncol,board,vis,delrow,delcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++){
            if(board[i][0] == 'O')dfs(i,0,board,vis,delrow,delcol);
            if(board[i][m-1] == 'O')dfs(i,m-1,board,vis,delrow,delcol);
        }
        for(int i = 0 ; i < m ; i++){
            if(board[0][i] == 'O')dfs(0,i,board,vis,delrow,delcol);
            if(board[n-1][i] == 'O')dfs(n-1,i,board,vis,delrow,delcol);
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == 0) board[i][j] = 'X';
            }
            cout<<endl ;
        }
    }
};