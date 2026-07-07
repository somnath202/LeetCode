class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int>arr;
        while(n > 0) {
            if(n%10 == 0){
                n /= 10 ;
                 continue ;
            }
            arr.push_back(n%10);
            n /= 10 ;
        }
        long long ans = 0 ;
        int size = arr.size() ;
        long long sum = 0 ;
        for(int i = 0 ; i < size ; i++){
            cout<<arr[i]<<" ";
            ans += arr[i] * pow(10,i);
            sum+= arr[i];
        }
        return ans*sum ;
    }
};