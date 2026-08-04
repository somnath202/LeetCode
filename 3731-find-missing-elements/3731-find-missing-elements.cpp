class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size() , maxi = nums[0] , mini = nums[0] ;
        unordered_map<int,int>mpp;
        for(auto it : nums){
            mpp[it]++;
            maxi = max(maxi,it);
            mini = min(mini,it);
        }
        vector<int>ans;
        for(int i = mini+1 ; i < maxi ; i++){
            if(mpp.find(i) == mpp.end()) ans.push_back(i);
        }
        return ans ;
    }
};