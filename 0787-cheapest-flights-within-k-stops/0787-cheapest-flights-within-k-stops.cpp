class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});

        }
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
         >pq;       // stops , station , cost

         vector<int>cost(n,INT_MAX);

         pq.push({0,{src,0}});
         cost[src] = 0 ;

        while(!pq.empty()){
            int stop = pq.top().first;
            int station = pq.top().second.first ;
            int d = pq.top().second.second ;
            pq.pop();
            for(auto it : adj[station]){
                if(stop <= k && (d + it.second) < cost[it.first]){
                    cost[it.first] = d + it.second ;
                    pq.push({stop+1 , {it.first , d + it.second}});
                }
            }
        }

        if (cost[dst] == INT_MAX) return -1 ;
        return cost[dst] ;
    }
};