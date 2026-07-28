class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size() ;
        sort(s.begin(),s.begin()+n/2);
        if(n%2 != 0){
            sort(s.begin()+n/2+1,s.end());
            reverse(s.begin()+n/2+1,s.end());
            return s ;
        }
        sort(s.begin()+n/2,s.end());
        reverse(s.begin()+n/2,s.end());
        return s ;
    }
};