class Solution {
public:
    int rob(vector<int>& nums) {
        
        int ans = robTabulation(nums);

        return ans;
    }

    int robTabulation(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> dp(n,-1);

        dp[n - 1] = nums[n-1];

        for(int i = n - 2 ; i >= 0 ; i--)
        {
            int tempAns = 0 ;

            if(i + 2 < n)
            {
                tempAns = dp[i + 2];
            }

            int include = nums[i] + tempAns ;
            int exclude = 0 + dp[i + 1] ;

            dp[i] = max(include,exclude);
        }

        return dp[0];
    }

    
};