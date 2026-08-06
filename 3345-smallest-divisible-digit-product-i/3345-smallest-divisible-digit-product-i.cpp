class Solution {
public:
    int product(int n){
        int pro = 1 ;
        while(n > 0){
            pro *= n % 10 ;
            n/= 10 ;
        }
        return pro ;
    }
    int smallestNumber(int n, int t) {
        for(int i = n ; i < INT_MAX ; i++){
            if(product(i)%t == 0) return i ;
        }
        return 1;
    }
};