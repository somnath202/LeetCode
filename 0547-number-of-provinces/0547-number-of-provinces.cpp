class Solution {
public:
    void dfs(vector<int>&ls,vector<int>&vis,int node , vector<int>adj[]){
        vis[node] = 1 ;
        ls.push_back(node);
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(ls,vis,it,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int>ls;
        vector<int> adj[v+1] ;
        for(int i = 0 ; i < v ; i++){
            for(int j = 0 ; j < v ; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(v,0);
        int count = 0 ;
        for(int i = 0 ; i < v ; i++){
            if(!vis[i]){
                dfs(ls,vis,i,adj);
                count++;
            }
        }
        return count ;
    }
};