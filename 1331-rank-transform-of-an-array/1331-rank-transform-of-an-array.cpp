class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>nums(arr.begin() , arr.end());
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int idx = 1 ;
        unordered_map<int,int>mpp;
        for(int i = 0 ; i < n ; i++){
            int it = arr[i];
            if(mpp.find(it) == mpp.end()){
                mpp[it] = idx++ ;
            }
        }
        vector<int>ans;
        for(auto it : nums){
            int x = mpp[it] ;
            ans.push_back(x);
        }
        return ans ;
    }
};