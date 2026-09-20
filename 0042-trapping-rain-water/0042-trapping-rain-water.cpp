class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftmax(n,0),rightmax(n,0);
        int maxi = height[0]  ;
        for(int i = 1 ; i < n ; i++){
            leftmax[i] = maxi ;
            maxi = max(maxi,height[i]);
        }
        maxi = height[n-1] ;
        for(int i = n-1 ; i >= 0 ; i--){
            rightmax[i] = maxi ;
            maxi = max(maxi , height[i]);
        }
        int ans = 0 ;
        for(int i = 1 ; i < n-1 ; i++){
            int x = min(leftmax[i],rightmax[i]) - height[i] ;
            if(x > 0){
                ans +=  x ;
            }
            cout<<ans<<" ";
        }
        return ans ;
    }
};