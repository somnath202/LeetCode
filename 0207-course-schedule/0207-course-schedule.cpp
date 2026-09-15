class Solution {
public:
  
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<int>adj[numCourses];
        for(auto it : prerequisites){
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]) ;
        }
        queue<int>q;
        for(int i = 0 ; i < indegree.size() ; i++){
            if(indegree[i] == 0) q.push(i) ;
        }
        while(!q.empty()){
            int node = q.front() ;
            q.pop();

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        for(auto it : indegree){
            if(it != 0) return 0 ;
        }
        return 1 ;
    }
};