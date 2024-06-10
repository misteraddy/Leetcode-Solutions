class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int maxlen = 0 ;
        
        int n = nums.size() ;

        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] == 0)
            {
                nums[i] = (-1);
            }
        }

        int sum = 0 ;

        unordered_map<int,int> mpp ;

        for(int i = 0 ; i < n ; i++)
        {
            sum += nums[i];

            if(sum == 0)
            {
                maxlen = max(maxlen,i+1);
            }

            if(mpp.find(sum) != mpp.end())
            {
                int len = i - mpp[sum];
                maxlen = max(len,maxlen);
            }

            if(mpp.find(sum) == mpp.end())
            {
                mpp[sum] = i ;
            }
        }

        return maxlen ;
    }
};