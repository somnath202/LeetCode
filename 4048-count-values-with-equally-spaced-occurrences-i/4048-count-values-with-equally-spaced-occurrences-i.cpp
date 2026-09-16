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
                if(nums[j] == a){
                    for(int k = j+1 ; k < n ; k++){
                        if(nums[k] == a){
                            if(k-j == j-i) count++;
                        }
                    }
                }
            }
        }
        return count ;
    }
};