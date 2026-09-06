class Solution {
public:
    void allSubset(int i , vector<int> &nums , vector<int>&arr , vector<vector<int>> &ans){
        
        ans.push_back(arr);
        for(int index= i ; index < nums.size() ; index++){

            if(index > i && nums[index] == nums[index-1]){
                continue ;
            }
            arr.push_back(nums[index]);
            allSubset(index+1 , nums,arr,ans);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>arr;
        allSubset(0,nums,arr,ans);
        return ans;
    }
};