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
        >pq;

        vector<int>time(n+1,INT_MAX);
        pq.push({0,k});
        time[k] = 0 ;

        while(!pq.empty()){
            int t = pq.top().first ;
            int node = pq.top().second ;
            pq.pop();

            for(auto it : adj[node]){
                if(t+it.second < time[it.first]){
                    time[it.first] = t + it.second ;
                    pq.push({time[it.first],it.first});
                }
            }
        }
        int maxi = INT_MIN ;
        for(auto it : time ) cout<<it<<" ";
        for(int i = 1 ; i < n+1 ; i++){
            if(time[i] == INT_MAX) return -1 ;
            maxi = max(maxi , time[i]);
        }
        return maxi ;
    }
};