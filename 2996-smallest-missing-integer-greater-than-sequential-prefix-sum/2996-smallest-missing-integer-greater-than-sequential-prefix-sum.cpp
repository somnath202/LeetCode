class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size(); 
        unordered_map<int,int>mpp;
        for(auto it : nums) mpp[it]++;
        int l = 0 , r = nums[0] ;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] != nums[i-1]+1) break ;
            r += nums[i] ;
        }
        for(int i = r ; i < INT_MAX ; i++){
            if(mpp.find(i) == mpp.end()) return i ;
        }
        return 0 ;
    }
};