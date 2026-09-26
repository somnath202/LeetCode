class Solution {
public:
    int help(int n , int stop , vector<int>nums , vector<int>&dp){
        if( n == stop ) return nums[n] ;
        if(n < stop) return 0 ;
        if(dp[n] != -1) return dp[n] ;
        int l = 0 + help(n-1 , stop , nums , dp);
        int r = nums[n] + help(n-2 , stop , nums , dp) ;

        return dp[n] = max(l,r) ;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0] ;
        vector<int>dp1(n,-1),dp2(n,-1);
        int ans1 = help(n-1 , 1 , nums,dp1);
        int ans2 = help(n-2 , 0 , nums,dp2);
        return max(ans1,ans2) ;
    }
};