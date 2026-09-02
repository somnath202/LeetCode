class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size() ;
        int idx = 0 , sum = 0 , count = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(idx < k){
                idx++;
                sum += arr[i] ;
            }else{
                int temp = sum / k ;
                if(temp >= threshold) count++;
                sum += arr[i] ;
                sum -= arr[abs(i-k)];
            }
        }
        int temp = sum / k ;
        if(temp >= threshold) count++;
        return count ;
    }
};