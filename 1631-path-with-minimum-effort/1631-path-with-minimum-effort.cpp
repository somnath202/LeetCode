class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>>diff(row,vector<int>(col,INT_MAX));

        pq.push({0,{0,0}}) ;
        diff[0][0] = 0 ;
        int adjrow[] = {-1,0,1,0};
        int adjcol[] = {0,1,0,-1};

        while(!pq.empty()){
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int d = pq.top().first;
            pq.pop();

            for(int i = 0 ; i < 4 ; i++){
                int newr = r + adjcol[i] ;
                int newc = c + adjrow[i];

                if(newr < row && newr >= 0 && newc < col && newc >= 0 && abs(heights[newr][newc] - heights[r][c]) < diff[newr][newc] ) {
                    int dist = abs(heights[newr][newc] - heights[r][c]) ;
                    int newdist = max(d,dist);
                    if(newdist < diff[newr][newc]){
                        diff[newr][newc] = newdist ;
                        pq.push({diff[newr][newc],{newr,newc}});
                    }
                }
            }
        }
        for(auto it : diff){
            for(auto i : it) cout<<i<<" ";
            cout<<endl;
        }
        return diff[row-1][col-1] ;
    }
};