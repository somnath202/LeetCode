class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0 ;
        int count = 0 ;
        sort(nums.begin(),nums.end());
        for(int j = 1 , i = 0 ; j < n   ; j++){
            if(nums[i] == nums[j])continue ;
            count++,i++;
        }
        return count; 
    }
};