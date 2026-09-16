class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i = 0 ; i < nums.size() ; i++) mpp[nums[i]] = i ;
        for(auto it : mpp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            int temp = target-nums[i] ;
            if(mpp.find(temp ) != mpp.end() && i != mpp[temp]) return {i,mpp[temp]};
        }
        return {};
    }
};