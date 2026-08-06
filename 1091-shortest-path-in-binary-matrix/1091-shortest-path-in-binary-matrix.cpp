class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        if(grid[0][0] == 1) return -1 ;
        pq.push({1, {0, 0}});
        dist[0][0] = 1;

        while (!pq.empty()) {
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int adjr = r + i;
                    int adjc = c + j;
                    if (adjr >= 0 && adjr < n && adjc >= 0 && adjc < n &&
                        grid[adjr][adjc] == 0 && d + 1 < dist[adjr][adjc]) {
                        dist[adjr][adjc] = d + 1;
                        pq.push({d + 1, {adjr, adjc}});
                    }
                }
            }
        }
        for (auto it : dist) {
            for (auto i : it)
                cout << i << " ";
            cout << endl;
        }
        int ans = 0;
        dist[n - 1][n - 1] == INT_MAX ? ans = -1 : ans = dist[n - 1][n - 1];
        return ans;
    }
};