class Solution {
public:
    int fun(int i , vector<int>nums , vector<int>&dp){
        if(i == 0) return nums[i] ;
        if(i < 0) return 0 ;
        if(dp[i] != -1) return dp[i] ;
        int f = nums[i] ;
        if(i > 1) f = nums[i] + fun(i-2 , nums, dp) ;

        int s = fun(i-1 , nums , dp);

        return dp[i] =  max(f,s);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        int ans =  fun(n-1 , nums,dp);
        // for(auto it : dp) cout<<it<<" ";
        return ans ;
    }
};