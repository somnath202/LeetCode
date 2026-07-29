class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size() ;
        vector<vector<int>>vis(n,vector<int>(m,0)),dist(n,vector<int>(m));
        queue<pair<pair<int,int>,int>>q ;

        //put all 0's to queue
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0) {
                    q.push({{i,j},0});
                    vis[i][j] = 1 ;
                }
            }
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second ;
            int d = q.front().second ;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && nrow<n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && mat[nrow][ncol] == 1){
                    q.push({{nrow,ncol},d+1});
                    vis[nrow][ncol] = 1 ;
                    dist[nrow][ncol] = d+1 ;
                    cout<<"aksjnehvmgd";
                }
            }
            
        }
        return dist ;


    }
};