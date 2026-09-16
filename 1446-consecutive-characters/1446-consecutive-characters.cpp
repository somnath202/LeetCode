class Solution {
public:
    int maxPower(string s) {
        int n = s.size() , l = 0 , r = 0 ;
        int ans = 0 ;
        while(r < n){
            if(s[l] == s[r]){
            ans = max(ans,r-l+1);
            r++;
            }
            else {
                l = r ;
            }
        }
        return ans ;
    }
};