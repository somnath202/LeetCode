class Solution {
public:
    bool check(int start , vector<vector<int>>&graph , vector<int>color ){
        int n = graph.size();
        queue<int>q;
        q.push(start);
        color[start] = 0 ;
        while(!q.empty()){
            int node = q.front() ;
            q.pop();
            for(auto it : graph[node]){
                if(color[it] == -1){
                    q.push(it);
                    color[it] = 1 - color[node] ;
                }else if(color[it] == color[node]){
                    return 0 ;
                }
            }
        }
        return 1 ;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i = 0 ; i < n ; i++){
            if(!check(i,graph,color)) return 0 ;
        }
        return 1 ;
    }
};