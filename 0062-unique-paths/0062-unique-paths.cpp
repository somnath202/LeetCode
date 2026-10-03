class Solution {
public:
    int memorization(int i , int j , int n , int m, vector<vector<int>>&dp){
        if(i <  0 || j < 0) return 0;
        if(i == 0 && j == 0) return 1 ;

        if(dp[i][j] != -1) return dp[i][j] ;

        int right = memorization(i,j-1,n,m,dp);
        int down = memorization(i-1 , j , n , m,dp) ;

        return dp[i][j] = right + down ;
    }
    
    int tabulation(int n , int m ){
        vector<vector<int>>dp(n,vector<int>(m,1));
        // for(int j = 0 ; j < m ; j++) dp[0][j] =  1;
        // for(int i = 0 ; i < n ; i++) dp[i][0] = 1 ;
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                int down = 0 , right = 0 ;
                if(i > 0  ) down = dp[i-1][j] ;
                if(j > 0) right = dp[i][j-1] ;
                dp[i][j] = down + right ;
            }
        }
      
        return dp[n-1][m-1] ;
    }

    int optimize(int n , int m ){
        vector<int>dp(m,0);
        dp[0] = 1 ;
        for(int i = 0 ; i < n ; i++){
            vector<int>temp(m,0);
            temp[0] = 1 ;
            for(int j = 1 ; j < m ; j++){
                temp[j] = dp[j] + temp[j-1] ;
            }
            dp = temp ;
        }
        return dp[m-1] ;
    }

    int uniquePaths(int n, int m) {
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return memorization(n-1,m-1,n,m,dp) ;
       

        return  optimize(n,m);
    }
};