class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1,-1);
        
        int ans = solve(coins,amount,dp);

        if(ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }

#if 0
    int solve(vector<int>& coins,int amount)
    {
        if(amount == 0)
        {
            return 0;
        }

        int mini = INT_MAX ;

        for(int i = 0 ; i < coins.size() ; i++)
        {
            if(amount - coins[i] >= 0)
            {
                int recursionKaAns = solve(coins,amount - coins[i]);

                //agar invalid answer hai toh INT_MAX return hoga
                //valid answer aane par mini update hoga 
                if(recursionKaAns != INT_MAX)
                {
                    int ans = 1 + recursionKaAns ;
                    mini = min(INT_MAX,ans);
                }
            }
            
        }

        return mini ;
    }

#endif

    int solve(vector<int>& coins,int amount,vector<int>& dp)
    {
        if(amount == 0)
        {
            return 0;
        }

        if(dp[amount] != (-1))
        {
            return dp[amount];
        }

        int mini = INT_MAX;

        for(int i = 0 ; i < coins.size() ; i++)
        {
        
            if(amount - coins[i] >= 0)
            {
                int recursionKaAns = solve(coins,amount - coins[i],dp);

                if(recursionKaAns != INT_MAX)
                {
                    int ans = 1 + recursionKaAns;
                    mini = min(mini,ans);
                }
            }
        }

        dp[amount] = mini ;

        return dp[amount];
    }


};