class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        // int n = s.size();
        
        // vector<int> dp(n,(-1));

        bool ans = solveUsingMemo(s,wordDict);

        return ans ;
    }

#if 0
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

#endif

    bool solveUsingMemo(string s,vector<string>& wordDict)
    {
        vector<int> dp(s.size() + 1);

        int index = s.size();

        dp[index] = true ;

        for(int start = s.size() - 1 ; start >= 0 ; start--)
        {
            bool flag = false;
            string word = "";
            for(int i = start ; i < s.size() ; i++)
            {
                word += s[i];

                if(check(wordDict,word))
                {
                    flag = flag || dp[i + 1];
                }
            }

            dp[start] = flag ;
        }

        return dp[0];
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