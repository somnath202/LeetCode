class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>premax(n,0),sufmin(n,0);
        int maxi = nums[0] , mini = nums[n-1];
        premax[0] = maxi ;
        sufmin[n-1] = mini ;
        for(int i = 1 ; i < n ; i++){

            premax[i] = max(premax[i-1],nums[i]);
        }
        for(int i = n-2 ; i >= 0 ; i--){
            sufmin[i] = min(sufmin[i+1],nums[i]);
        }
        for(int i = 0 ; i < n ; i++){
            premax[i] = premax[i] - sufmin[i];
            if(premax[i] <= k) return i ;
        }

        return -1 ;
    }
};