class Solution {
public:
    void help(vector<int>nums , int i , vector<int>&arr , vector<vector<int>>& ans , vector<int>& used){
        if(arr.size() == nums.size()){
            ans.push_back(arr);
            return ;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(used[i]) continue ;
            arr.push_back(nums[i]);
            used[i] = 1 ;
            help(nums,i , arr,ans,used);
            arr.pop_back();
            used[i] = 0 ;            
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>arr , used(nums.size(),0);
        help(nums,0 , arr,ans,used);
        return ans ;
    }
};