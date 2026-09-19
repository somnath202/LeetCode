class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // unordered_map<int,int>mpp;
        // for(auto it : nums) mpp[it]++;
        // for(auto it : mpp ) if(it.second == 1) return it.first ;
        // return -1 ;

        int ones = 0 , twos = 0 ;
        for(auto it : nums){
            ones ^= (it & ~twos) ;
            twos ^= (it & ~ones);
        }
        return ones ;
    }
};