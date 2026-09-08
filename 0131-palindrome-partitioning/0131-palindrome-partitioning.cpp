class Solution {
public:
    bool isPallindrom(string s,int l , int r){
        while(l < r){
            if(s[l] != s[r]) return false ;
            l++,r--;
        }
        return true ;
    }
    void help(string s , int i , vector<string>&arr , vector<vector<string>>&ans ){
        if(i == s.size()){
            ans.push_back(arr);
            return ;
        }
        for(int j = i ; j < s.size() ; j++){
            if(isPallindrom(s,i,j)){
                arr.push_back(s.substr(i,j-i+1));
                help(s,j+1 , arr,ans);
                arr.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>arr;
        help(s,0,arr,ans);
        return ans ;
    }
};