class Solution {
public:
    void help(vector<int>nums , int i , int sum , vector<int>& arr , vector<vector<int>>& ans){
        if(sum == 0 ){
            ans.push_back(arr);
            return ;
        }
        if(sum < 0 || i == nums.size() ){
            return ;
        }
        arr.push_back(nums[i]);
        help(nums,i,sum - nums[i] ,arr,ans);
        arr.pop_back();
        help(nums,i+1 , sum , arr,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans ;
        vector<int>arr;
        help(candidates,0,target,arr,ans);
        return ans ;
    }
};