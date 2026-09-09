class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size() ;
        vector<int>ans ;
        int i = 0 , d = n ;
        for(int it = 0 ; it < n ; it++){
            if(s[it] == 'I') {
                ans.push_back(i++);
            }else ans.push_back(d--);
        }
        if(i < n) ans.push_back(i);
        else ans.push_back(d);
        return ans;
    }
};