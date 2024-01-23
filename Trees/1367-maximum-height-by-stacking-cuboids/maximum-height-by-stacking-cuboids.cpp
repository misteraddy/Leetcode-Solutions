class Solution {
public:

    bool check(vector<int>& curr,vector<int>& prev)
    {
        if(prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2])
        {
            return true;
        }

        return false;
    }

    int solve(vector<vector<int>>& cuboids,int prevIndex,int currIndex,vector<vector<int>>& dp)
    {
        if(currIndex >= cuboids.size())
        {
            return 0 ;
        }

        if(dp[currIndex][prevIndex + 1] != (-1))
        {
            return dp[currIndex][prevIndex + 1];  //index shifting kyunki prevIndex intital access pr error aayega kyunki (-1 ) is not a valid index
        }

        int include = 0 ;

        int exclude = 0 ;

        int ans = 0 ;

        if(prevIndex == (-1) || check(cuboids[currIndex],cuboids[prevIndex]))
        {
            include = cuboids[currIndex][2] + solve(cuboids,currIndex,currIndex + 1,dp);
        }

        exclude = 0 + solve(cuboids,prevIndex,currIndex + 1,dp);

        ans = max(include,exclude);

        return dp[currIndex][prevIndex + 1] = ans;
    }

    int maxHeight(vector<vector<int>>& cuboids) {

        for(auto &cuboid : cuboids)
        {
            sort(cuboid.begin(),cuboid.end());
        }

        sort(cuboids.begin(),cuboids.end());

        int n = cuboids.size();

        vector<vector<int>>dp(n + 1,vector<int>(n + 1,(-1)));

        int ans = solve(cuboids,-1,0,dp);

        return ans;
    }
};