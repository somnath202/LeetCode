class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>set;
        for(auto it : wordList) set.insert(it);
        if(set.find(endWord) == set.end()) return 0 ;
        while(!q.empty()){
            string s = q.front().first ;
            int no = q.front().second;
            set.erase(s);
            q.pop();
            for(int i = 0 ; i < s.size() ; i++){
                for(int j = 0 ; j < 26 ; j++){
                    string x = s ;
                    x[i] = 'a'+j ;
                    if(set.find(x) != set.end()){
                        if(x == endWord) return no+1 ;
                        q.push({x,no+1});
                    }
                }
            }
        }
        return 0 ; 
    }
};