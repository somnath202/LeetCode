class Solution {
public:
    // Tabular form 
    int fun(int n,vector<int>&dp){
        if(n < 0) return  0;
        if(n==0){
            return 1;
        }
        if(dp[n] != -1) return dp[n] ;
        int left = fun(n-1 , dp);
        int right = fun(n-2,dp);
        return dp[n] = left + right ;
    }
    int climbStairs(int n) {
        // vector<int>dp(n+1,-1);
        // int ans = fun(n,dp);
        // for(auto it : dp) cout<<it<<" ";
        // return ans ;
        if(n == 1) return 1 ;
        int a = 1 , b = 1 ;
        for(int i = 2 ; i <= n ; i++){
            int temp = b ;
            b += a ;
            a = temp ;
        }
        return b ;
    }
};