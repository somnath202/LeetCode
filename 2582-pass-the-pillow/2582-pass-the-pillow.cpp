class Solution {
public:
    int passThePillow(int n, int t) {
        int temp = 2 * n -2  ;
        t = t % temp ;
        if(t < n) return t+1 ;
        t = t - n ;
        return n-t-1 ;
    }
};