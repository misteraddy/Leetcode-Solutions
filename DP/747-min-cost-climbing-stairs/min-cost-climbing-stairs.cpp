class Solution {
public:
    int tabulation(vector<int>cost,int n)
    {
        vector<int>dp(n+1,0);
        for(int i=n-2;i>=0;i--)
        {
             int pick1=cost[i]+dp[i+1];
            int pick2=cost[i+1]+dp[i+2];
            dp[i]=min(pick1,pick2);
        }
        return dp[0];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        return  tabulation(cost,n);
    }
};