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
        // int ans =  fun(n-1 , nums,dp);
        // for(auto it : dp) cout<<it<<" ";


        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        // dp[0] = nums[0] ;
        // dp[1] = nums[1] ;
         int max1 = nums[0] , max2 = nums[1];
        // for(int i = 2 ; i< n ; i++){
        //     int f = nums[i] + max1 ;
        //     int s = max2 ;
        //     dp[i] = max(f,s);
        //     max1 = max(max1 , max2);
        //     max2 = max(max2 , dp[i]);
        // }
        // for(auto it : dp) cout<<it<<" ";
        // return dp[n-1];

        for(int i = 2 ; i < n ; i++){
            int temp = max2 ;
            max2 = max(nums[i]+max1 , max2);
            max1 = max(max1,temp);
        }
        return max2 ;
    }
};