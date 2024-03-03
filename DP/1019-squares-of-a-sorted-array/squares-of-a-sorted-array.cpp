class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0, right = n - 1, end = n - 1;
        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                res[end--] = nums[left] * nums[left++];
            } else {
                res[end--] = nums[right] * nums[right--];
            }
        }
        return res;
    }
};