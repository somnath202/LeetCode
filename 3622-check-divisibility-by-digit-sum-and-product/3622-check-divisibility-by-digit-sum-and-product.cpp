class Solution {
public:
    bool checkDivisibility(int n) {
        long long pro = 1 ;
        long long sum = 0 ;
        int temp = n ;
        while(temp > 0){
            int digit = temp % 10 ;
            pro *= digit ;
            sum += digit ;
            temp /= 10 ;
        }
        return (n % (pro+sum)) == 0;
    }
};