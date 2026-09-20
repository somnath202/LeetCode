class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minbuy = prices[0];
        for(auto it : prices){
            minbuy = min(minbuy,it);
            maxprofit = max(maxprofit,it-minbuy);
        }
        return maxprofit ;
    }
};