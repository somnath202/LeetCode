class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char>st;
        // st.push(s[0]);
        for(int i = 0 ; i < n ; i++){
            char it = s[i];
            if(it == '(') st.push(it);
            if(it == '[') st.push(it);
            if(it == '{') st.push(it);
            if(st.empty()) st.push(it);
            if(!st.empty()){
                if(it == ')'){
                    if(st.top() == '(') st.pop();
                    else return 0 ;
                }
                if(it == '}'){
                    if(st.top() == '{') st.pop();
                    else return 0 ;
                }
                if(it == ']' ){
                    if(st.top() == '[')st.pop();
                    else return 0 ;
                }
            }
        }
        return st.empty() ? 1 : 0 ;
    }
};