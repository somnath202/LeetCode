class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size() ;
        int count = 1 ;
        if(n <= 2) return n ;
        while( count <= n){
            count <<= 1;
        } 
        return count ;

    }
};