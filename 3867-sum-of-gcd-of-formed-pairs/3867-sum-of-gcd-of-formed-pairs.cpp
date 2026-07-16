class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = nums[0] ;
        for(int i = 0 ; i < nums.size() ; i++){
            mx = max(mx,nums[i]);
            nums[i] = gcd(nums[i],mx);

        }

        long long sum = 0 ;
        int l = 0 , r = nums.size()-1 ;

        sort(nums.begin(),nums.end());

        while(l < r){
            sum += gcd(nums[l],nums[r]);
            l++,r--;
        }
        return sum ;
    }
};