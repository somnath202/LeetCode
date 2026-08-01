class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int arr[n][n];
        for(int i = 0 ; i < n ; i++) arr[i][i] = nums[i] ;
        for(int len = 2 ; len <= n ; len++){
            for(int i = 0 , j = len-1 ;  j < n ; i++,j++){
                arr[i][j] = max(nums[i]-arr[i+1][j],nums[j]-arr[i][j-1]);
            }
        }
        if(arr[0][n-1] >= 0) return 1 ;
        return 0 ;
    }
};