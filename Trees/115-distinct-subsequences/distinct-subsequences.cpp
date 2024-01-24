class Solution {
public:
    int numDistinct(string s, string t) {

        vector<vector<int>> dp(s.length() + 1,vector<int>(t.length() + 1,(-1)));
        
        int ans = solve(s,t,0,0,dp);

        return ans;
    }

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
};