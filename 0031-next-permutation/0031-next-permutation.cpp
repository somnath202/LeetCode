class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), breakpoint = -1, firstmax;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakpoint = i;
                break;
            }
        }
        if (breakpoint == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            for (int i = n - 1; i >= 0; i--) {
                if (nums[i] > nums[breakpoint]) {
                    firstmax = i;
                    break;
                }
            }
            cout << breakpoint << " " << firstmax;
            int temp = nums[firstmax];
            nums[firstmax] = nums[breakpoint];
            nums[breakpoint] = temp;
            reverse(nums.begin() + breakpoint + 1, nums.end());
        }
    }
};