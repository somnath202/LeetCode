class Solution {
public:
    int help(int i , vector<int>cost , vector<int>&dp){
        if(i == 0) return 0 ;
        if(dp[i] != -1 && i != cost.size()-1) return dp[i];
        int left = help(i-1 , cost , dp) +  cost[i] ;
        int right = INT_MAX ;
        if(i > 1 ) right = help(i-2,cost,dp) + cost[i];

        return dp[i-1] = min(left,right) ;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        // dp[n-1] = 0 ;
        // int x = help(n-1,cost,dp);
        // return x ;
        // return dp[1] < dp[2] ? dp[1]:dp[2];
        dp[0] = cost[0] , dp[1] = cost[1];
        for(int i = 2 ;i < n ; i++){
            dp[i] = min(dp[i-1]+ cost[i] , dp[i-2] + cost[i]);
        }
        for(auto it : dp) cout<<it<<" ";
        return min(dp[n-1],dp[n-2]);
    }
};