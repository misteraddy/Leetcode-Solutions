class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0 ;

        for(auto num : nums)
        {
            sum += num ;  // Error ye tha sum += sum + num
        }

        //if the sum is odd then it cannot be divided into two halves 
        if(sum & 1)
        {
            return false;
        }

        int target = sum/2 ;

        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(target+1,-1));  // Error kiya: Change 'target' to 'target+1'

        bool ans = solveMemo(nums,0,0,target,dp);

        return ans ;    
    }

    bool solveMemo(vector<int>& nums,int index,int currSum,int target,vector<vector<int>>& dp)
    {
        if(index >= nums.size())
        {
            return false;  // Fix: Change '0' to 'false'
        }

        if(currSum == target)
        {
            return true;  // Fix: Change '1' to 'true'
        }

        if(currSum > target)
        {
            return false;
        }

        if(dp[index][currSum] != (-1))
        {
            return dp[index][currSum];
        }

        bool include = solveMemo(nums,index + 1,currSum + nums[index],target,dp);
        bool exclude = solveMemo(nums,index + 1,currSum,target,dp);

        return dp[index][currSum] = (include || exclude) ;  
    }
};
