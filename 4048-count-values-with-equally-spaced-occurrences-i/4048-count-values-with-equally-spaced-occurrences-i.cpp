class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        int count = 0 ;
        unordered_map<int,int>mpp;
        for(auto it : nums) mpp[it]++;
        for(int i = 0 ; i < n ; i++){
            int a = nums[i];
            if(mpp[a] != 3) continue ;
            for(int j = i+1 ; j < n ; j++){
                if(nums[j] == a && 2*j-i < n){
                    if(nums[2*j-i] == a) count++;
                }
            }
        }
        return count ;
    }
};