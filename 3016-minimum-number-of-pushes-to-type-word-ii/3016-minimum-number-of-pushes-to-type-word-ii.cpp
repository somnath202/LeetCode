class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mpp;
        for(auto it : word) mpp[it]++;
        vector<pair<char,int>>arr(mpp.begin(),mpp.end());
        sort(arr.begin(),arr.end(),[](auto & a ,auto &b ){
            return a.second > b.second ;
        });
        for(auto it : arr){
        }

        int click = 1 ;
        int i = 0 ;
        int count = 0 ;
        for(auto it : arr){
            cout<<it.first<<" : "<<it.second<<" "<<click<<endl;
            count += it.second * click ;
            i++;
            if(i % 8 == 0) click++;
        }

        return count ;
    }
};