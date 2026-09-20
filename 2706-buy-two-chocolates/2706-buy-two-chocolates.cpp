class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int f = INT_MAX , s = INT_MAX ;
        for(auto it : prices){
            if(it < f){
                s = f ;
                f = it ;
            }else if(it < s){
                s = it ;
            }
        }
        // cout<<f<<" "<<s;
        if(f+s <= money) return money-f-s;
        return money;
    }
};