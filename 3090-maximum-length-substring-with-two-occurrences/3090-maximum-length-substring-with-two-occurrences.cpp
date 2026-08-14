class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mpp;
            for (int j = i; j < n; j++) {
                mpp[s[j]]++;
                bool f = true;
                for (auto it : mpp) {
                    if (it.second > 2)
                        f = false;
                }
                if (f)
                    ans = max(ans, j-i+1 );
            }
        }
        return ans ;
    }
};