class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0 , j = 0 ;
        while(i < s.size() && j < t.size()){
            if(s[i] == t[j]) j++;
            i++;
        }
        return j == t.size() ;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0 ;
        unordered_map<string,int>mp,mpp;
        for(auto it : words) mp[it]++;
        for(auto itx : mp){
            string it = itx.first ;
            if(mpp.find(it) != mpp.end()) count += itx.second;
            else if(isSubsequence(s,it)){
                count+= itx.second;
                mpp[it]++;
            }
        }
        return count ;
    }
};