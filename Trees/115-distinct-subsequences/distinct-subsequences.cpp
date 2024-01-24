class Solution {
public:
    int numDistinct(string s, string t) {

        // vector<vector<int>> dp(s.length() + 1,vector<int>(t.length() + 1,(-1)));
        
        int ans = solve(s,t);

        return ans;
    }

#if 0
    int solve(string s,string t,int i,int j,vector<vector<int>>& dp)
    {
        if(j == t.size())
        {
            return 1 ;
        }

        if(i == s.size())
        {
            return 0 ;
        }

        if(dp[i][j] != (-1))
        {
            return dp[i][j];
        }

        int ans = 0 ;

        if(s[i] == t[j])
        {
            ans += solve(s,t,i + 1,j + 1,dp);
        }

        ans += solve(s,t,i + 1,j,dp);

        return dp[i][j] = ans;
    }

#endif


   int solve(string s, string t)
    {
        int m = t.size();
        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));   // -1 se initialised

        for (int i = 0; i <= n; i++)  //i < n
        {
            dp[i][m] = 1; //dp[i][m - 1] = 1; error
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                long long ans = 0;   //int 32 bit k paar pahuch rhai thi issiliye long long liya

                if (s[i] == t[j])
                {
                    ans += dp[i + 1][j + 1];
                }

                ans += dp[i + 1][j];

                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }


};