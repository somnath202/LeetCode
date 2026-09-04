class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = nums[0];
        vector<int>M,m;
        for(auto it : nums){
            maxi = max(maxi,it);
            M.push_back(maxi);
        }
        int n = nums.size();
        int mini = nums[n-1] ;
        for(int i = n-1 ; i >= 0 ; i--){
            mini = min(mini,nums[i]);
            m.push_back(mini);
        }
        reverse(m.begin(),m.end());
        for(int i = 0 ; i < n ; i++){
            int temp = M[i]-m[i] ;
            if(temp <= k ){
                return i ;
            }
        }
        return -1 ; 

    }
};