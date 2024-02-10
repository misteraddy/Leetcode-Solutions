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

//approach 2 : dp : memoisation

#if 0

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

#endif

//dp : tabulation 

int countSubstrings(string s) {
    int n = s.length();
    int count = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false)); // Initially all the values are false
    for (int L = 1; L <= n; L++) {
        for (int i = 0; i + L <= n; i++) {
            int j = i + L - 1; // 0 based indexing
            if (L == 1) { // Changed i == j to L == 1
                dp[i][j] = true;
            } else if (L == 2) { // Changed i + 1 == j to L == 2
                if (s[i] == s[j]) {
                    dp[i][j] = true;
                }
            } else {
                if (s[i] == s[j] && dp[i + 1][j - 1]) { // Corrected indexing for dp
                    dp[i][j] = true;
                }
            }
            if (dp[i][j]) {
                count++;
            }
        }
    }
    return count;
}


};


//redefinition in the same scope is not allowed line 24 and line 28