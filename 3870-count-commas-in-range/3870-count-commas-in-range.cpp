class Solution {
public:
    int countCommas(int n) {
        string s = to_string(n);
        int size = s.size();
        if(size < 4) return 0 ;
        int ans = n -1000 +1 ;
        return ans ;

    }
};