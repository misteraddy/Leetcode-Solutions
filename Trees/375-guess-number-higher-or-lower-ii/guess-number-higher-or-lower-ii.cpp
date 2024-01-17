class Solution {
public:
    int getMoneyAmount(int n) {
        
        int start = 0 ;

        int end = n ;

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        int ans = solveUsingMemo(start,end,dp);

        return ans;
    }

    int solveUsingMemo(int start,int end,vector<vector<int>>& dp)
    {
        //start == end single item wale case mei
        //usme bhi seedhe selection no penalty

        if(start >= end)
        {
            return 0 ;

            //uss case mei no penalty
        }

        if(dp[start][end] != (-1))
        {
            return dp[start][end];
        }

        int ans = INT_MAX ;

        for(int i = start ; i <= end ; i++)
        {
            ans = min(ans, i + max(solveUsingMemo(start, i - 1,dp), solveUsingMemo(i + 1,end,dp)));
        }

        dp[start][end] = ans ;

        return dp[start][end] ;
    }
};