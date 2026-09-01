class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = false;
        vector<int> ans;
        int n = digits.size();
        int firstsum = digits[n - 1] + 1;
        if (firstsum > 9) {
            carry = true;
            ans.push_back(firstsum % 10);
        } else {
            ans.push_back(firstsum);
        }
        for (int i = n - 2; i >= 0; i--) {
            int temp = digits[i];
            if (carry) {
                temp++;
            }
            if (temp > 9) {
                carry = true;
                ans.push_back(temp % 10);
            } else {
                carry = false ;
                ans.push_back(temp);
            }
        }
        if(carry) ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans ;
    }
};