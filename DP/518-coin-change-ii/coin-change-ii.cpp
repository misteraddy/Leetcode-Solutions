class Solution {
public:
    int change(int amount, vector<int>& coins) {

        // vector<vector<int>>dp(amount + 1,vector<int>(coins.size() + 1,(-1)));

        // int ans = solve(amount,0,coins,dp);
        
        int ans = solve(amount,coins);

        return ans;
    }

#if 0
    int solve(int amount,int index,vector<int>& coins,vector<vector<int>>& dp)
    {
        if(index >= coins.size())
        {
            return 0 ;
        }

        if(amount == 0)
        {
            return 1 ;
        }

        if(dp[amount][index] != (-1))
        {
            return dp[amount][index];
        }

        int ans = 0 ;

        for(int i = index ; i < coins.size() ; i++)
        {
            if(amount - coins[i] >= 0)
            {
                ans += solve(amount - coins[i],i,coins,dp);
            }
        }

        return dp[amount][index] = ans ;
    }
#endif

    int solve(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, 0));

        // Base case: there is one way to make change for amount 0, i.e., by not selecting any coin.
        for (int i = 0; i <= coins.size(); ++i) {
            dp[0][i] = 1;
        }

        for (int i = 1; i <= amount; ++i) {
            for (int j = 1; j <= coins.size(); ++j) {
                // Initialize ans to the number of ways without considering the current coin.
                int ans = dp[i][j - 1];

                // If the current coin can be used to make change for the remaining amount.
                if (i - coins[j - 1] >= 0) {
                    ans += dp[i - coins[j - 1]][j];
                }

                dp[i][j] = ans;
            }
        }

        return dp[amount][coins.size()];
    }

};