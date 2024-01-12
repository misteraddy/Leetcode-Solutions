class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.length();

        int m = word2.length();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        int ans = solve(word1,word2,0,0,dp);

        return ans;
    }

    int solve(string word1,string word2,int i,int j,vector<vector<int>>& dp)
    {
        if(i >= word1.length())
        {
            return (word2.length() - j);
        }

        int ans = 0 ;

        if(j >= word2.length())
        {
            return (word1.length() - i);
        }

        if(dp[i][j] != (-1))
        {
            return dp[i][j];
        }

        if(word1[i] == word2[j])
        {
           ans = 0 + solve(word1,word2,i+1,j+1,dp);
        }
        else
        {
            int insert = 1 + solve(word1,word2,i,j+1,dp);
            int del = 1 + solve(word1,word2,i+1,j,dp);
            int update = 1 + solve(word1,word2,i + 1,j + 1,dp);

            ans = min(insert,min(del,update));
        }

        dp[i][j] = ans ;

        return dp[i][j];
    }
};