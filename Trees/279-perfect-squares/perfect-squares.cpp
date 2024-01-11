class Solution {
public:
    int numSquares(int n) {

        vector<int> temp ;

        vector<int> dp(n+1,-1);

        int finalans = solve(n, dp);

        return finalans;
    }

    int solve(int n, vector<int>& dp)
    {
        if(n == 0)
        {
            return 0;
        }

        if(dp[n] != -1)
        {
            return dp[n];
        }

        int ans = INT_MAX;

        for(int i = 1 ; i <= sqrt(n) ; i++) // Start i from 1
        {
            if(n - i*i >= 0)
            {
                int recursionKaAns = solve(n - i*i, dp);
                ans = min(ans, 1 + recursionKaAns); // Take the minimum
            }
        }
        dp[n] = ans;

        return dp[n];
    }
};
