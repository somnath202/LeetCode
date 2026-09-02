class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0 , count = 0 ;
        int n = s.size() ;
        int idx = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(idx < k){
                idx++;
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ) count++;
            }else{
                ans = max(count , ans ) ;
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ) count++;
                if(s[abs(i-k)] == 'a' || s[abs(i-k)] == 'e' || s[abs(i-k)] == 'i' || s[abs(i-k)] == 'o' || s[abs(i-k)] == 'u' ) count--;
            }
        }
        ans = max(ans,count);
        return ans ;
    }
};