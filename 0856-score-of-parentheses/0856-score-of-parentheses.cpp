class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size() ;
        stack<int>st;

        for(auto it : s ){
            if(it == '(') st.push(-1) ;
            else{
                if(!st.empty() && st.top() == -1) {
                    st.pop();
                    st.push(1);
                }else if(!st.empty()){
                    int temp = 0 ;
                    while(!st.empty() && st.top() != -1){
                        temp += st.top();
                        st.pop();
                    }
                    temp *= 2 ;
                    st.pop();
                    st.push(temp);
                }
             }
        }
        int ans = 0 ;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};