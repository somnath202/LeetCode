class Solution {
public:
    void help(int i , vector<int>nums , vector<int>&arr , vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(arr);
            return  ;
        }
        arr.push_back(nums[i]);
        help(i+1 , nums, arr , ans);
        arr.pop_back();
        help(i+1 , nums , arr , ans) ;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans ;
        vector<int>arr;
        help(0 , nums , arr , ans);
        return ans ;
    }
};