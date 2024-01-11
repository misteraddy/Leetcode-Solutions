class Solution {
public:

#if 0
    int mincostTicketsHelper(vector<int>& days, vector<int>& costs,int i,vector<int>& dp)
    {
        if(i >= days.size())
        {
            return 0;
        }

        if(dp[i] != (-1))
        {
            return dp[i];
        }

        //1 day ka
        int c1 = costs[0] + mincostTicketsHelper(days,costs,i + 1,dp);

        //7 days pass

        int passday = days[i] + 7 - 1 ;

        int j = i ;

        while(j < days.size() && days[j] <= passday)
        {
            j++;
        }

        int c2 = costs[1] + mincostTicketsHelper(days,costs,j,dp);

        passday = days[i] + 30 - 1 ;

        j = i ;

        while(j < days.size() && days[j] <= passday)
        {
            j++;
        }

        int c3 = costs[2] + mincostTicketsHelper(days,costs,j,dp);
        
        return dp[i] = min(c1,min(c2,c3));
    }

#endif

    int mincostTicketsHelper(vector<int>& days, vector<int>& costs)
    {
        int n = days.size();

        vector<int> dp(n + 1,-1);

        dp[n] = 0 ;

        for(int i = n - 1 ; i >= 0 ; i--)
        {
            //1 day ka
            int c1 = costs[0] + dp[i + 1];

            //7 days pass

            int passday = days[i] + 7 - 1 ;

            int j = i ;

            while(j < days.size() && days[j] <= passday)
            {
                j++;
            }

            int c2 = costs[1] + dp[j];

            passday = days[i] + 30 - 1 ;

            j = i ;

            while(j < days.size() && days[j] <= passday)
            {
                j++;
            }

            int c3 = costs[2] + dp[j];

            dp[i] = min(c1,min(c2,c3));
        }
    
        return dp[0];  
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {

        // int n = days.size();

        // vector<int> dp(n,-1);

        return mincostTicketsHelper(days,costs);
    }
};