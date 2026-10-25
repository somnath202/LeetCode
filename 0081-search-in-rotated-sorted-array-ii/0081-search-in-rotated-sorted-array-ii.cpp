class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0 , h = nums.size()-1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(nums[mid] == target) return true ;
            if(nums[l] == nums[mid] && nums[mid] == nums[h]) h--,l++;
            else if(nums[mid] >= nums[l]){
                if(target < nums[mid] && target >= nums[l] ) h = mid-1;
                else l = mid+1;
            }else{
                if(target > nums[mid] && target <= nums[h]) l = mid+1 ;
                else h = mid -1 ;
            }
                cout<<mid<<" ";
        }
        return false ;
    }
};