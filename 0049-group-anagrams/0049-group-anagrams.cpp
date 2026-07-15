class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<vector<string>>ans ;
        // int size = strs.size();
        // for(int i = 0 ; i < size ; i++){
        //     unordered_map<char,int>mpp ;
        //     string str = strs[i] ;
        //     if(str == "-1") continue ;
        //     for(auto it : str) mpp[it]++;
        //     vector<string>temp ;
        //     temp.push_back(str);
        //     for(int j = i+1 ; j < size ; j++){

        //         string s = strs[j];
        //         if(s == "-1" ) continue ;
        //         unordered_map<char,int>mp(mpp) ;
        //         for(auto it : s){
        //              mp[it]--;
        //         }
        //         cout<<mp.size()<<" ";
        //         if(mp.size()==0){
        //             temp.push_back(s);
        //             cout<<s<<" ";
        //             strs[j] = "-1";
        //         }
        //     }
        //     ans.push_back(temp);

        // }
        // return ans ;

        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& p : mp)
            ans.push_back(p.second);
            
        return ans;
    }
};