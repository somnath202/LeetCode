class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mpp;
        for(auto it : knowledge) mpp[it[0]] = it[1];

        int n = s.size();
        string ans = "";
        int l = 0 ;
        string temp = "";
        bool f = false ;
        for(int r = 0 ; r < n ; r++){
            if(s[r] == '('){
                l = r ;
                ans += temp ;
                f = true ;
                temp = "" ;
            }if(s[r] == ')'){
                f = false ;
                if(mpp.find(temp) != mpp.end()){
                    ans += mpp[temp];
                }else ans += "?" ;
                temp = "";

            }
            if(f && s[r] != '('){
                temp += s[r] ;
            }
            if(!f && s[r] != ')'){
                temp += s[r] ;
            }
        }
        ans += temp ;
        return ans ;
    }
};