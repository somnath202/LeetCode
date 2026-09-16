class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int l = 0 , r = nums.size()-1 ;
        long long ans = 0 ;
        while(l <= r){
            string s = "" ;
            if(l==r) s = to_string(nums[l]) ;
            else s = to_string(nums[l]) + to_string(nums[r]);
            ans += stoi(s);
            l++,r--;
        }
        return ans ;
    }
};