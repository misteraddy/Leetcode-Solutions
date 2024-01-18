class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> dp(n + 1, -1);

        int ans = solveUsingMemoisation(n,dp);

        return ans ;
        
    }

    int solveUsingMemoisation(int n,vector<int>& dp)
    {
        if(n < 0)
        {
            return 0 ;
        }

        if(n == 0)
        {
            return 1 ;
        }

        if(dp[n] != (-1))
        {
            return dp[n];
        }

        int ans = 0 ;

        ans = solveUsingMemoisation(n - 1,dp) + solveUsingMemoisation(n - 2,dp);

        dp[n] = ans ;

        return dp[n] ;
    }
};