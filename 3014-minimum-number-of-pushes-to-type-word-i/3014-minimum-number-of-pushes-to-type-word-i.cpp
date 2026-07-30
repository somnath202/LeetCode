class Solution {
public:
    int minimumPushes(string word) {
        int count = 0 ;
        int n = word.size() ;
        int click = 1 ;
        while(n > 0){
            int temp = n % 8 ;
            if(n/8 > 0){
                count += click * 8 ;
                cout<<count<<" ";
                n -= 8 ;
            }
            else {
                count += click * temp ;
                n -= temp ;
            }
            click++ ;
        }
        return count ;
    }
};