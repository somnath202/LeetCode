class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        int n = s.size();
        int i = 1 ;
        st.push(s[0]);
        while(i < n){
            if( !st.empty() && (s[i] == 'B'&& st.top() == 'A' || s[i] == 'D' && st.top() == 'C')) {
                st.pop();

            }else st.push(s[i]);
            i++;
        }
        return st.size() ;
    }
};