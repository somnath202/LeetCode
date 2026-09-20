class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int maxi = 0 , left = 0 ;
        for(int right = 0 ; right < s.size() ; right++){
            mpp[s[right]]++;
            while(mpp.size() < right-left+1){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0) mpp.erase(s[left]);
                left++;
            }
            maxi = max(maxi,right-left+1);
        }
        return maxi ;
    }
};