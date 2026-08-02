class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = 0, n = s.size();
        while (left < n && right <= n) {
            for (right; right < n; right++) {
                if (s[right] == ' ') break;
            }
            int r = right - 1;
            while (left < r) {
                char temp = s[left];
                s[left] = s[r];
                s[r] = temp;
                left++, r--;
            }
            left = right + 1;
            right++;
        }

        return s;
    }
};