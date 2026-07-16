class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        for (int i = 1; i < size; i++)
            nums[i] += nums[i - 1];
        int count = 0 ;
        unordered_map<int,int>mp;
        for (int i = 0 ; i < size ; i++) {
           if(nums[i] == k) count++ ;
           if(mp.find(nums[i]-k) != mp.end()) count += mp[nums[i]-k];
           mp[nums[i]]++;
        }
        return count ;
    }
};