class Solution {
public:
    
    //global variables hai

    int maxlen = 1 ;  //yaha maine 0 kiya tha

    int start = 0 ;

    bool isPalindrome(string& s,int i,int j,vector<vector<int>>& dp)
    {

        if(i >= j)
        {
            return true;
        }

        if(dp[i][j] != (-1))
        {
            return dp[i][j];
        }

        bool flag = false;

        if(s[i] == s[j])
        {
            flag = isPalindrome(s,i+1,j-1,dp);
        }

        if(flag == true)
        {
            int currlen = j - i + 1 ;

            if(maxlen < currlen)
            {
                maxlen = currlen;
                start = i;
            }
        }

        return dp[i][j] = flag;
    }

    string longestPalindrome(string s) {

        int n = s.size();

        vector<vector<int>>dp(n,vector<int>(n,-1));

        //@d vector
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            for(int j = i ; j < s.size() ; j++)
            {
                 bool k = isPalindrome(s,i,j,dp);
            }
        }

        return s.substr(start,maxlen);

    }
};