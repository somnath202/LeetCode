class Solution {
public:
    int findGCD(vector<int>& nums) {
        int s = INT_MAX ;
        int l = INT_MIN ;
        for(auto it : nums){
            s = min(s,it);
            l = max(l,it);

        }
        return gcd(s,l);
    }
};