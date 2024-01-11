class Solution {
public:
    int numSquares(int n) {

        vector<int> temp ;

        // vector<int> dp(n+1,-1);

        int finalans = solve(n);

        return finalans;
    }

#if 0
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
#endif

    int solve(int n)
{
    vector<int> dp(n + 1, -1);

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int ans = INT_MAX;
        for (int j = 1; j * j <= i; j++)  // Error kiya re
        {
            if (i - j * j >= 0)
            {
                int recursionKaAns = dp[i - j * j];
                ans = min(ans, 1 + recursionKaAns);
            }
        }
        dp[i] = ans;
    }

    return dp[n];
}

};
