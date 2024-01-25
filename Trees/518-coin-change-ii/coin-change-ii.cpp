class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<vector<int>>dp(amount + 1,vector<int>(coins.size() + 1,(-1)));

        int ans = solve(amount,0,coins,dp);
        
        return ans;
    }

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
};