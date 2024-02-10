class Solution {
public:

#if 0 //string wale approach se 

    int expand(string s,int i,int j)
    {
        int count = 0 ;

        while(i >= 0 && j < s.size() && s[i] == s[j])
        {
            i--;
            j++;
            count++;
        }

        return count ;
    }

    int countSubstrings(string s) {

        int total = 0 ;
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            int j = i ;

            int oddKaAns = expand(s,i,j);

            j = i + 1 ;

            int evenKaAns = expand(s,i,j);

            total = oddKaAns + evenKaAns + total ;
        }

        return total ;
    }

#endif

//approach 2 : dp 

// #if 0

int countSubstrings(string s) {

    int ans = solve(s);

    return ans ;
}

int solve(string s)
{
    int ans = 0 ;

    int n = s.size();

    vector<vector<int>> dp(n,vector<int>(n,-1));

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i ; j < n ; j++)
        {
            if(check(i,j,s,dp))
            {
                ans += 1 ;
            }
        }
    }

    return ans ;
}

bool check(int i,int j,string s,vector<vector<int>>& dp)
{
    if(i >= j)
    {
        return true;
    }

    if(dp[i][j] != (-1))
    {
        return dp[i][j];
    }

    bool flag = false ;

    if(s[i] == s[j])
    {
        flag = check(i+1,j-1,s,dp);
    }

    return dp[i][j] = flag;
}

// endif

};


//redefinition in the same scope is not allowed line 24 and line 28