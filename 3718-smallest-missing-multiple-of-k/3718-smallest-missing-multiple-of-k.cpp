class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto it : nums) mpp[it]++;
        for(int i = 1 ; i < INT_MAX ; i++){
            int temp = k * i ;
            if(mpp.find(temp) == mpp.end()) return temp ;
        }
        return 0 ;
    }
};