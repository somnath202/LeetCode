class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX , miniidx = -1 ;
        int maxi = INT_MIN ,maxiidx = -1;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                maxiidx = i ;
            }
            if(nums[i] < mini){
                mini = nums[i] ;
                miniidx = i ;
            }
        }
        cout<<maxi<<" "<<mini<<endl;
        int l = min(miniidx,maxiidx) ;
        int r = max(miniidx,maxiidx);
        int one = r+1 , two = n-l, three = l + n-r+1 ;
        cout<<one<<" "<<two<<" "<<three;
        return min(one,min(two,three));
    }
};