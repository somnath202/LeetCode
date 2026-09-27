class Solution {
public:
    void help(int i , int n , int k , vector<int>arr , vector<vector<int>>&ans){
        if(arr.size() == k) {
            ans.push_back(arr);
            return ;
        }
        for(int idx = i ; idx <= n ; idx++){
            arr.push_back(idx);
            help(idx + 1 , n , k , arr , ans);
            arr.pop_back() ;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>arr;
        help(1,n,k,arr,ans);
        return ans ;
    }
};