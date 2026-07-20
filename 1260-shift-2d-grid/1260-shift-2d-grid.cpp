class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size();
        while(k--){
            vector<int>arr;
            for(auto it : grid){
                arr.push_back(it[m-1]);
            }
            int first = grid[n-1][m-1];
            int last = grid[0][m-1]  ;
            for(int i = 0 ; i < n ; i++){
                int temp = grid[i][0] ;
                if(i >= 1) last = grid[i][m-1]  ;
                for(int j = 1; j < m ; j++){
                    int l = grid[i][j] ;
                    grid[i][j] = temp ;
                    temp = l ;
                }
                
                grid[i][0] = last ;
                
            }
            grid[0][0] = first ;
            for(int i = 1 ; i < n ; i++){
                grid[i][0] = arr[i-1];
            }
        }
        return grid ;
    }
};