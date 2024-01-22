class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 1)
        {
            return nums[0];
        }
        
        vector<int> nums2 ;

        vector<int> nums3 ;

        for(int i = 0 ; i < nums.size() - 1 ; i++)
        {
            nums2.push_back(nums[i]);
        }

        for(int j = 1 ; j < nums.size() ; j++)
        {
            nums3.push_back(nums[j]);
        }

        vector<int> dp2(nums2.size(),(-1));

        vector<int> dp3(nums3.size(),(-1));

        int ans2 = solve(nums2,0,dp2);

        int ans3 = solve(nums3,0,dp3);

        return max(ans2,ans3);
    }

    int solve(vector<int>& nums,int i,vector<int>& dp)
    {
        if(i >= nums.size())
        {
            return 0;
        }
 
        if(dp[i] != (-1))
        {
            return dp[i];
        }

        int ans = 0 ;
        
        int include = nums[i] + solve(nums,i + 2,dp);

        int exclude = 0 + solve(nums,i + 1,dp);

        ans = max(include,exclude);

        return dp[i] = ans;
    }
};