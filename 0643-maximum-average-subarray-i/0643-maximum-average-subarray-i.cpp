class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN ;
        double sum = 0 ;
        int n = nums.size() ;
        int idx = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(idx < k  ){
                sum += nums[i] ;
                idx++;
            }else{
                double temp = sum / k ;
                if(temp > ans ) ans = temp ;
                sum += nums[i] ;
                sum -= nums[abs(k-i)] ;
            }
            
        }
        double temp = sum / k ;
        if(temp > ans ) ans = temp ;
        return ans ;

    }
};