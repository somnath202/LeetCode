class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int n = intervals.size();
        for(int i = 1 ; i < n ; i++){
            int size = ans.size();
            int x = ans[size-1][1];
            int y= intervals[i][0];
            int z = intervals[i][1];
            int f = ans[size-1][0];
            if(y <= x){
                ans.pop_back();
                ans.push_back({f,max(x,max(y,z))});
            }else{
                ans.push_back({y,z});
            }
        }
        return ans ;
    }
};