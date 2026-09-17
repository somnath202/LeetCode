class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int left = 0;
        int sum = 0 ;
        int ans = INT_MAX , minlen = INT_MAX;
        vector<int>best(arr.size() , INT_MAX);
        for(int right = 0 ; right < arr.size() ; right++){
            sum += arr[right];
            while(sum > target){
                sum -= arr[left];
                left++;
            }
            if(sum == target){
                int len = right-left+1;
                if(left > 0 && best[left-1] != INT_MAX){
                    ans = min(ans,len+best[left-1]);
                }
                minlen = min(minlen,len);
            }
            best[right] = minlen ;
        }
        return ans == INT_MAX ? -1 : ans ;
    }
};