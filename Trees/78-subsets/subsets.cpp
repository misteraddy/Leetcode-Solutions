class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;

        int n = nums.size();

        vector<int> temp ;

        solve(nums, ans, n, 0, temp);

        return ans;
    }

    void solve(vector<int>& nums, vector<vector<int>>& ans, int n, int start, vector<int>& temp)
    {
        ans.push_back(temp);

        for (int i = start; i < n; i++)
        {
            int element = nums[i];

            temp.push_back(element);

            solve(nums, ans, n, i + 1, temp);

            temp.pop_back();
        }
    }
};