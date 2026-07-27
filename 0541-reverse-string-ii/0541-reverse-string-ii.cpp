class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0 ;
        if(s.size() == 1) return s ;
        while(i < s.size()){
            if(i+k >= s.size()){
                reverse(s.begin()+i , s.end());
                cout<<s<<" ";
            }else{
                reverse(s.begin()+i , s.begin()+i+k);
            }
            i+= 2*k;
        } 
        return s;
    }
};