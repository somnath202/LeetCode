class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool nonZero = false ;
        int ans = 0 ;
        for(auto it : nums){
            if(it != 0) nonZero = true ;
            ans ^= it ;
        }
        int n = nums.size();
        if(nonZero && ans != 0) return n ;
        if(nonZero) return n-1;
        return 0 ;

    }
};