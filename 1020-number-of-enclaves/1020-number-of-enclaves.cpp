class Solution {
public:
    void dfs(int r , int c , vector<vector<int>>&grid , vector<vector<int>>& vis,int delrow[] , int delcol[]){
        vis[r][c] = 1 ;
        int n = grid.size() , m = grid[0].size();
        for(int i = 0 ; i < 4 ; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if(nrow >= 0 && nrow < n  && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,grid,vis,delrow,delcol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0) vis[i][j] = 1;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(grid[i][0] == 1)dfs(i,0,grid,vis,delrow,delcol);
            if(grid[i][m-1] == 1)dfs(i,m-1,grid,vis,delrow,delcol);
        }
        for(int i = 0 ; i < m ; i++){
            if(grid[0][i] == 1)dfs(0,i,grid,vis,delrow,delcol);
            if(grid[n-1][i] == 1)dfs(n-1,i,grid,vis,delrow,delcol);
        }
        int count = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == 0) count++;
            }
        }
        return count ;
    }
};