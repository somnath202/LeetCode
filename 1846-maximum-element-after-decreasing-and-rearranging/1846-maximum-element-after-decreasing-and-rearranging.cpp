class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int ans ;
        int size = arr.size() ;
        arr[0] = 1 ;
        for(int i = 1 ; i < size ; i++){
            if(arr[i] - arr[i-1] <= 1) continue ;
            else arr[i] = arr[i-1] + 1 ;
        }
        return arr[size-1];
    }
};