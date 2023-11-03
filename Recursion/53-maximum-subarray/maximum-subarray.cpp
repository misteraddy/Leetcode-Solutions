class Solution {
public:
    int maxSumFinder(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }

        int mid = start + (end - start) / 2;

        int left = maxSumFinder(nums, start, mid);
        int right = maxSumFinder(nums, mid + 1, end);


        int left_sum = 0; // Initialize left_sum
        int max_left_sum = INT_MIN; // Initialize max_left_sum

        for (int index = mid; index >= start; index--) {
            left_sum = left_sum + nums[index];
            if(max_left_sum < left_sum )
            {
              max_left_sum  = left_sum;
            }
        }

        int right_sum = 0; // Initialize right_sum
        int max_right_sum = INT_MIN; // Initialize max_right_sum

        for (int index = mid + 1; index <= end; index++) {
            right_sum = right_sum + nums[index];
            if(max_right_sum < right_sum )
            {
              max_right_sum  = right_sum;
            }
        }

        int combine = max_left_sum + max_right_sum;


        int maxi = max(left, max(right, combine));

        return maxi;
    }

    int maxSubArray(vector<int>& nums) {
        int ans = maxSumFinder(nums, 0, nums.size() - 1);

        return ans;
    }
};