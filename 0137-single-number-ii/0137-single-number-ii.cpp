class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // unordered_map<int,int>mpp;
        // for(auto it : nums) mpp[it]++;
        // for(auto it : mpp ) if(it.second == 1) return it.first ;
        // return -1 ;

        int ones = 0 , tows = 0 ;
        for(auto it : nums){
            ones ^= (it & ~tows) ;
            tows ^= (it & ~ones);
        }
        return ones ;
    }
};