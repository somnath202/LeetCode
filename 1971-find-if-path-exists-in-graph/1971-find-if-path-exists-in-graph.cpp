class Solution {
public:
    void dfs(int start , vector<int>adj[] , vector<int>&vis){
        vis[start] = 1 ;
        
        for(auto it : adj[start]){
            if(!vis[it] ){
                dfs(it,adj,vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n] ;
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);

        dfs(source,adj,vis);
        if(vis[destination ]) return 1 ;
        
        return 0 ;
    }
};