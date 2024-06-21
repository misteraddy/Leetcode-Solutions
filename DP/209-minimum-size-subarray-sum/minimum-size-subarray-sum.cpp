class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int len = INT_MAX ;

        int s = 0 ;

        int e = 0 ;

        int sum = 0 ;

        int n = nums.size();

        while(e < n) {

            sum += nums[e];

            while(sum >= target) {

                sum -= nums[s];

                len = min(len,e-s+1);
                s++;

            }

            e++;

        }

        if(len == INT_MAX) {
            return 0 ;
        } else {
            return len ;
        }
    }
};