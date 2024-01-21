class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();
        
        vector<int> dp(n,(-1));

        bool ans = solveUsingMemo(s,wordDict,0,dp);

        return ans ;
    }

    bool solveUsingMemo(string s,vector<string>& wordDict,int start,vector<int>& dp)
    {
        if(start == s.size())
        {
            return true;
        }

        string word = "";

        if(dp[start] != (-1))
        {
            return dp[start];
        }

        bool flag = false;

        for(int i = start ; i < s.size() ; i++)
        {
            word += s[i];

            if(check(wordDict,word))
            {
                flag = flag || solveUsingMemo(s,wordDict,i + 1,dp);
            }
        }

        dp[start] = flag;

        return flag;
    }

    bool check(vector<string>& wordDict,string word)
    {
        for(auto i : wordDict)
        {
            if(word == i)
            {
                return true;
            }
        }

        return false;
    }
};