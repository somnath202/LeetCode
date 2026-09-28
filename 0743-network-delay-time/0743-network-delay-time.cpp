class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue< 
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        >q;
        q.push({0,k});
        vector<int>dist(n+1 , INT_MAX);
        dist[k] = 0 ;

        while(!q.empty()){
            int node = q.top().second;
            int wt = q.top().first ;
            q.pop();

            for(auto it : adj[node]){
                int newwt = wt + it.second ;
                int newnode = it.first ;
                if(newwt < dist[newnode]){
                    dist[newnode] = newwt ;
                    q.push({newwt,newnode});
                }
            }
        }
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            if(dist[i] == INT_MAX) return -1 ;
            ans = max(ans,dist[i]);
        }
        return ans ;
    }
};