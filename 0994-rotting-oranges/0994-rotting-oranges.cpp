class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int minutes = 0 ;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 1 ;
                    q.push({0,{i,j}});
                }
                if(grid[i][j] == 0) vis[i][j] = -1 ;
            }
        }
        int adjrow[] = {-1,0,1,0};
        int adjcol[] = {0,1,0,-1};
        while(!q.empty()){
            int minute = q.front().first ;
            int r = q.front().second.first;
            int c = q.front().second.second ;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int newrow = r + adjrow[i];
                int newcol = c + adjcol[i];
                if(newrow < n && newrow >= 0 && newcol < m && newcol >= 0 && vis[newrow][newcol] == 0 && grid[newrow][newcol] == 1){
                    q.push({minute+1,{newrow,newcol}});
                    grid[newrow][newcol] = 2 ;
                    vis[newrow][newcol] = 1 ;
                    minutes = max(minutes,(minute+1));
                 }
            }
        }
        for(auto it : grid){
            for(auto i : it){
                if(i == 1) return -1 ;
            }
        }
        return minutes ;
    }
};