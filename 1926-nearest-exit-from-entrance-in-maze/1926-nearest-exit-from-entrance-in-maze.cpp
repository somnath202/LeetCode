class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        int adjrow[] = {-1,0,1,0};
        int adjcol[] = {0,1,0,-1};

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(maze[i][j] == '.'){
                    vis[i][j] = 1 ;
                }
            }
        }
        q.push({0,{entrance[0],entrance[1]}});
        vis[entrance[0]][entrance[1]] = 0 ;

        while(!q.empty()){
            int step = q.front().first ;
            int r = q.front().second.first ;
            int c = q.front().second.second ;
            q.pop();
            
            for(int i = 0 ; i < 4 ; i++){
                int row = r + adjrow[i];
                int col = c + adjcol[i] ;
                if((row >= n || row < 0 || col >= m || col < 0) && step != 0){
                    return step  ;
                }if(row < n && row >= 0 && col < m && col >= 0 && maze[row][col] == '.' && vis[row][col] == 1){
                    q.push({step+1,{row,col}});
                    vis[row][col] = 0 ;
                }
            }
        }
        
        return -1 ;
    }
};