class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN ;
        int prifix = 1 , suffix = 1 ;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            prifix *= nums[i];
            suffix *= nums[n-i-1];

            ans = max(ans , max(prifix,suffix));
            if(prifix == 0) prifix = 1 ;
            if(suffix == 0) suffix = 1 ;
        }
        return ans ;
    }
};