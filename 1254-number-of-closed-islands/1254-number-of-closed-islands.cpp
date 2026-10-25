class Solution {
public:
    bool dfs(int r , int c , vector<vector<int>>&grid , vector<vector<int>>&vis){
        int m = grid.size() , n = grid[0].size() ;
        bool closed = true ;
        if(r == 0 || c ==0 || r == m-1 || c == n-1) closed = false ; 
        vis[r][c] = 1 ;
        int adjrow[] = {-1 , 0 , 1 , 0};
        int adjcol[] = {0 , 1 , 0 , -1};
        for(int i = 0 ; i < 4 ; i++){
            int row = r + adjrow[i];
            int col = c + adjcol[i];
            if(row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 0 && vis[row][col] != 1){
                if(!dfs(row,col,grid,vis)){
                    closed = false ;
                }
            }
        }
        
        return closed ;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>>vis(row,vector<int>(col,0));
        int count = 0 ;
        for(int i = 1 ; i < row-1 ; i++){
            for(int j = 1 ; j < col-1 ; j++){
                if(grid[i][j] == 0 && vis[i][j] == 0){
                    
                    if(dfs(i,j,grid,vis)) count++;
                } 
            }
        }
        return count ;
    }
};