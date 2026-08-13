class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = INT_MIN ;
        int n = nums.size() ;

        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                int64_t temp = (1LL*nums[i]*nums[j]) / ((1LL*gcd(nums[i],nums[j]))*(gcd(nums[i],nums[j]))) ;
                if(ans < temp) ans = temp ;
            }
        }
        return ans ;
    }
};