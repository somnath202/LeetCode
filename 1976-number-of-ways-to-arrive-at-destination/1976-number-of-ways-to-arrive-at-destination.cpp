class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = int(1e9+7) ;
        vector<pair<int,long long>>adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>time(n,LLONG_MAX);
        vector<long long>ways(n,0) ;
        priority_queue<
            pair<long long,long long>,
            vector<pair<long long,long long>>,
            greater<pair<long long,long long>>
        >pq;

        pq.push({0,0});
        time[0] = 0 ;
        ways[0] = 1 ;

        while(!pq.empty()){
            long long t = pq.top().first ;
            int node = pq.top().second ;
            pq.pop();
 
            for(auto it : adj[node]){
                long long nt = it.second ;
                long long nn = it.first ;
                if(t + nt < time[nn]){
                    ways[nn] = ways[node] ;
                    time[nn] = t + nt ;
                    pq.push({t+nt , nn});
                }
                else if(nt+t == time[nn]) ways[nn] = (ways[nn]+ ways[node])%MOD;
            }
        }


        return ways[n-1]%MOD ;
    }
};