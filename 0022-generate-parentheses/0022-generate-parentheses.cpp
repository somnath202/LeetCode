class Solution {
public:
    bool is_permutation(string s){
        stack<char>st;
        int n = s.size();
        for(auto it : s){
            if(it == '(') st.push('(') ;
            if(it == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop() ;
                }
            }
        }
        return st.empty() ;
    }
    vector<string> generateParenthesis(int n) {
        string s = "" ;
        for(int i = 0 ; i < n ; i++) s += "(" ;
        for(int i = 0 ; i < n ; i++) s += ")" ;
        vector<string>ans ;
        do{
            if(is_permutation(s)) ans.push_back(s) ;
        }while(next_permutation(s.begin(),s.end()));
        return ans ;
    }
};