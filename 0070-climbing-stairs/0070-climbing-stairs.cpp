class Solution {
public:
    int fun(int n,vector<int>&dp){
        if(n < 0) return  0;
        if(n==0){
            return 1;
        }
        int left = 0, right = 0;
        if(dp[n-1]!= -1) left = dp[n-1] ;
        else {
            left = fun(n-1,dp);
            dp[n-1] = left ;
        }
        if( n-2 >= 0 && dp[n-2] != -1) right = dp[n-2] ;
        else if(n-2 >= 0) {
            right = fun(n-2,dp);
            dp[n-2] = right ;
        }
        return left + right ;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        for(auto it : dp) cout<<it<<" ";
        return fun(n,dp);
        
    }
};