class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        // int n = text1.size();

        // int m = text2.size();

        // vector<vector<int>>dp(n,vector<int>(m,-1)); //INT_MAX se bhi initialise kar sakte hai 
        
        int ans = solve(text1,text2);

        return ans;
    }

#if 0
    int solve(string& text1,string& text2,int i,int j,vector<vector<int>>& dp)
    {   
        if(i >= text1.length())
        {
            return 0 ;
        }

        if(j >= text2.length())
        {
            return 0 ;
        }

        if(dp[i][j] != (-1))
        {
            return dp[i][j];
        }

        int ans = 0 ;

        if(text1[i] == text2[j])
        {
            ans = 1 + solve(text1,text2,i+1,j+1,dp);
        }
        else
        {
            ans = 0 + max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp));
        }

        dp[i][j] = ans ;

        return dp[i][j];
    }
#endif

    int solve(string& text1,string& text2)
    {   

        int n = text1.length() ;

        int m = text2.length() ;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//sabko 0 se inittialise

        //otherwise hum log loop lagake last col and last row ki saari values ko 0 kar dete hai

        int ans = 0;
        for(int i = n - 1 ; i >= 0 ; i-- )
        {
            for(int j = m - 1 ; j >= 0 ; j-- )
            {
                if(text1[i] == text2[j])
                {
                     ans = 1 + dp[i+1][j+1];
                }
                else
                {
                    ans = 0 + max(dp[i+1][j],dp[i][j+1]);
                }

                dp[i][j] = ans ;
            }
        }

        return dp[0][0];
    }

};