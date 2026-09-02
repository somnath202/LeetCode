class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n = nums.size() ;
        for(int i = 0 ; i <= k && i < n  ; i++){
            if(mpp.find(nums[i]) != mpp.end()) return true ;
            mpp[nums[i]]++;
        }
        for(int i = k+1 ; i < n ; i++){
            mpp[nums[abs(i-k-1)]]--;
            cout<<mpp[nums[i]]<<" ";
            if(mpp.find(nums[i]) != mpp.end() && mpp[nums[i]] != 0) return true ;
            mpp[nums[i]]++;
        }
        return false ;

    }
};