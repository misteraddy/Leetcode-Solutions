class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int count = 0 ;

        int sum = 0 ;

        map<int,int> mpp ;

        mpp[0] = 1 ;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum += nums[i];

            int rem = sum - goal ;

            count += mpp[rem] ;

            mpp[sum] += 1 ;
        }

        return count ;
    }
};