class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {

        // vector<vector<int>>dp(s1.length() + 1,vector<int>(s2.length() + 1,-1));
        
        int ans = solve(s1,s2);

        return ans ;
    }

#if 0
    int solve(string s1,string s2,int i ,int j,vector<vector<int>>&dp)
    {
        int ans = 0 ;

        if(dp[i][j] != (-1))
        {
            return dp[i][j];
        }

        if(i == s1.length() || j == s2.length())
        {

            for(int x1 = i ; x1 < s1.length() ; x1++) ans += s1[x1];

            for(int x2 = j ; x2 < s2.length() ; x2++) ans += s2[x2];

            return ans;
        }
        
            if(s1[i] == s2[j])
            {
                ans = 0 + solve(s1,s2,i+1,j+1,dp);
            }
            else
            {
                int c1 = s1[i] + solve(s1,s2,i+1,j,dp);
                int c2 = s2[j] + solve(s1,s2,i,j+1,dp);

                ans = min(c1,c2);
            }

        return dp[i][j] = ans ;

    }
#endif

    int solve(string s1,string s2)
    {
        vector<vector<int>>dp(s1.size() + 1,vector<int>(s2.size() + 1,0));

        for(int i = s1.size() - 1 ; i >= 0 ; i--)
        {
            dp[i][s2.size()] = s1[i] + dp[i + 1][s2.size()];
        }

        for(int j = s2.size() - 1 ; j >= 0 ; j--)
        {
            dp[s1.size()][j] = s2[j] + dp[s1.size()][j + 1];
        }

        for(int i = s1.size() - 1 ; i >= 0 ; i--)
        {
            for(int j = s2.size() - 1 ; j >= 0 ; j--)
            {
                int ans = 0 ;
                if(s1[i] == s2[j])
                {
                    ans = 0 + dp[i+1][j+1];
                }
                else
                {
                    int c1 = s1[i] + dp[i+1][j];
                    int c2 = s2[j] + dp[i][j+1];

                    ans = min(c1,c2);
                }

                dp[i][j] = ans ;

            }
        }

        return dp[0][0];
    }

};