class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0 ;
        for(int i = 1 ; i < nums.size()-1 ; i++){
            float temp = nums[i]/2.0 ;
            if(temp == nums[i-1]+nums[i+1]) count++;
        }
        return count ;
    }
};