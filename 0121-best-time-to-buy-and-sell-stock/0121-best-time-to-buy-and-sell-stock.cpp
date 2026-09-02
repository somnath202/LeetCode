class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX ;
        int n = prices.size() , ans = 0 ;
        for(auto it : prices){
            buy = min(buy , it) ;
            ans = max(ans , it-buy);
        }
        return ans ;
    }
};