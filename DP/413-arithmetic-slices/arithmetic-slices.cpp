class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();      // Size of nums
        int ans = 0;              // Initializing answer as 0, which will count the total number of Arithmetic subarrays
        vector<int> temp(n, 0);   // Temp array for counting the number of arithmetic subarrays 

        // Looping from the 3rd element and checking if the common difference between the 3rd and 2nd element is equal to the 2nd and 1st element. 
        // If yes, then it's an Arithmetic subarray.
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                temp[i] = temp[i - 1] + 1; 
                ans += temp[i];
            }
        }
        return ans;
    }
};
