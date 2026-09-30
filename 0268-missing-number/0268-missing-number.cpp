class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // long long expected = n * (n+1) / 2 ;
        // long long sum = 0 ;
        // for(auto it : nums) sum += it ;
        // int ans = expected - sum ;
        // return ans ;
        int ans = 0 ;
        int idx = 1 ;
        for(auto it : nums){
            ans ^= it  ^ idx++;
        }
        return ans ;
        
    }
};