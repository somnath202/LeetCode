class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i = 1 ; i < intervals.size() ; i++){
            // cout<<ans[i-1][0]<<endl;
            if(intervals[i][0] <= ans[ans.size()-1][1]){
                int temp = ans[ans.size()-1][0],x = ans[ans.size()-1][1] ;
                ans.pop_back();
                ans.push_back({temp, max(intervals[i][1],x ) });
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans ;
    }
};