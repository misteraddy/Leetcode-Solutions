class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();

        int count = 0 ;
        
        map<int,int> mpp ;

        mpp[0] = 1 ;

        long long sum = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
            sum += nums[i];

            int remainder = (sum % k);

            if(remainder < 0)
            {
                remainder = remainder + k ;
            }

            count = count + mpp[remainder];

            mpp[remainder]++;
        }

        return count;
    }
};