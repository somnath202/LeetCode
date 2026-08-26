class Solution {
public:
    bool smallerBinary(string a, string b) {
        int i = 0;
        while (i < a.size() && a[i] == '0')
            i++;
        a = a.substr(i);

        i = 0;
        while (i < b.size() && b[i] == '0')
            i++;
        b = b.substr(i);

        if (a.empty())
            a = "0";
        if (b.empty())
            b = "0";

        if (a.size() != b.size())
            return a.size() < b.size();

        return a < b;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        for (int left = 0; left < n; left++) {
            int count = 0;
            if (s[left] == '0')
                continue;
            for (int i = left; i < n; i++) {
                if (s[i] == '1')
                    count++;
                if (count == k) {
                    string temp = s.substr(left, i - left + 1);
                    if (ans == "")
                        ans = temp;
                    else if (temp.size() < ans.size())
                        ans = temp;
                    else if (temp.size() == ans.size() &&
                             smallerBinary(temp, ans))
                        ans = temp;
                    cout << temp << endl;
                    break;
                }
            }
        }
        return ans;
    }
};