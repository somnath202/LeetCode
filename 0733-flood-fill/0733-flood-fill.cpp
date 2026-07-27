class Solution {
    void dfs(vector<vector<int>> &image, vector<vector<int>>& ans, int row,
             int col, int newcolor, int inicolor, int delrow[],
             int delcol[]) {
        ans[row][col] = newcolor;
        int r = image.size();
        int c = image[0].size() ;
        for(int i = 0 ; i < 4 ; i++){
            int nrow = row + delrow[i] ;
            int ncol = col + delcol[i] ;
            if(nrow >= 0 && ncol >= 0 && nrow < r && ncol < c && image[nrow][ncol] == inicolor && ans[nrow][ncol] != newcolor){
                dfs(image,ans,nrow,ncol,newcolor,inicolor,delrow,delcol);
            }
        }
        
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        dfs(image, ans, sr, sc, color, inicolor, delrow, delcol);
        return ans ;
    }
};