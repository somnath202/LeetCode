class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(nums1.size() != 0 && n-- && nums1[nums1.size()-1] == 0 ) {
            nums1.pop_back();
        }
        cout<<nums1.size();
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin() , nums1.end());

    }
};