class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        st.push(s[0]);
        int n = s.size() ;
        for(int i = 1 ; i < n ; i++){
            if(st.empty() ) {
                if(s[i] != '*') st.push(s[i]);
                continue ;
            }
            if(s[i] == '*') {
                st.pop();
            }else st.push(s[i]);
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        int l = 0 , r = ans.size()-1 ;
        while(l < r){
            char temp = ans[l] ;
            ans[l] = ans[r];
            ans[r] = temp ;
            l++,r--;
        }
        return ans ;
    }
};