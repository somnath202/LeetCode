class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        // int n = word1.size();
        // int m = word2.size();

        // vector<int>next(m,-1);
        // for(int i = n-1 , j = m-1 ; i >= 0 && j >= 0 ; i--){
        //     if(word2[j] == word1[i] ){
        //         next[j] = i ;
        //         j--;
        //     }
        // }

        // vector<int>ans(m);
        // bool canchange = true ;
        // int j = 0 ;
        // for(int i = 0 ; i < n && j < m; i++){
        //     if(next[j] != -1){
        //         ans[j] = i ;
        //     }else if(canchange){
        //         ans[j] = i ;
        //         canchange = false ;
        //     }
        //     j++;
        // }
        // for(auto it : next ) cout<<it<<" ";
        // return ans ;

        int N=word1.size();
        int M=word2.size();
        int R=M-1;
        int C=0;
        vector<int> Right(N);
        for(int i=N-1;i>=0;i--){
            Right[i]=C;
            if(R>=0 && word1[i]==word2[R]){
                R--;
                C++;
            }
        }
        vector<int> ans;
        bool changed=false;
        int j=0;
        for(int i=0;i<N && j<M;i++){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!changed && Right[i]>=M-1-j){
                ans.push_back(i);
                j++;
                changed=true;
            }
        }
        if(j==M){
            return ans;
        }
        return {};
    }
};