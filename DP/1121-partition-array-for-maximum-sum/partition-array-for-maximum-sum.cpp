class Solution {
public:
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
    int maxSumAfterPartitioning(vector<int>& v, int k) {
        int n = v.size();
        dp.assign(n,-1);
        return f(0,v,k);
    }
};