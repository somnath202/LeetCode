class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int co = image[sr][sc] ;
        vector<vector<int>>vis(n,vector<int>(m,0)),ans = image;
        queue<pair<int,int>>q ;
        q.push({sr,sc});
        ans[sr][sc] = color ;
        vis[sr][sc] = 1 ;
        int adjrow[] = {-1,0,1,0};
        int adjcol[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second ;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int row = r + adjrow[i];
                int col = c + adjcol[i];
                if(row < n && row >= 0 && col < m && col >= 0 && image[row][col] == co && vis[row][col] == 0){
                    ans[row][col] = color ;
                    vis[row][col] = 1 ;
                    q.push({row,col});
                }
            }
        }
        return ans ;
    }
};