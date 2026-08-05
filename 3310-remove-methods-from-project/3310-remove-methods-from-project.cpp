class Solution {
public:
    void dfs(int node , vector<int>adj[] , vector<int>&vis){
        vis[node] = 1 ;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>adj[n];
        for(auto it : invocations){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>vis1(n,0),vis2(n,0);
        vector<int>ans1,ans2;

        dfs(k,adj,vis1);
        for(int i = 0 ; i < n ; i++){
            if(!vis1[i] && !vis2[i]){
                dfs(i,adj,vis2);
            }
        }
        bool f = false ;
        for(int i = 0 ; i < n ; i++){
            if(vis1[i] == vis2[i]) f = true ;
            if(vis2[i] ) ans1.push_back(i);
            if(vis2[i] || vis1[i]) ans2.push_back(i);
        }
        if(f) return ans2 ;
        return ans1 ;
    }
};