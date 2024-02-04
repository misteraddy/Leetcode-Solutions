class Solution {
public:

#if 0

    vector<int>dp;

    int f(int ind, vector<int>&v, int k){
        int n = v.size();
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1)
            return dp[ind];

        int s = 0;
        int maxi = 0;
        for(int i = ind; i<n; i++){
            maxi = max(maxi,v[i]);
            if(i-ind+1<=k)
                s = max(s, maxi*(i-ind+1)+f(i+1,v,k));
        }
        return dp[ind] = s;
    }

#endif

    //tabulation

    int f(vector<int>&v, int k)
    {
        int n = v.size() ;

        vector<int> dp(n + 1,-1);

        dp[n] = 0 ;

        for(int ind = n - 1 ; ind >= 0 ; ind--)
        {
            int maxi = 0 ;

            int s = 0 ;

            for(int i = ind ; i < n ; i++)
            {
                maxi = max(maxi,v[i]);

                if(i - ind + 1 <= k)
                {
                    s = max(s, maxi*(i - ind + 1) + dp[ i + 1]);
                }
            }

            dp[ind] = s ;
        }

        return dp[0];
    }

    
    int maxSumAfterPartitioning(vector<int>& v, int k) {
        int n = v.size();
        // dp.assign(n,-1);
        // return f(0,v,k);

        int ans = f(v,k);

        return ans ;
    }
};