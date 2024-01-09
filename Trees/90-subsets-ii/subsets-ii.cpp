class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        // Sort the input to handle duplicates
        sort(nums.begin(), nums.end());
        
        find(nums, 0, ans, temp);
        
        return ans;
    }
    
    void find(vector<int>& nums, int start, vector<vector<int>>& ans, vector<int>& temp) {
        ans.push_back(temp);  // Include the empty subset
        
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;  // Skip duplicates
            }
            
            temp.push_back(nums[i]);
            find(nums, i + 1, ans, temp);
            temp.pop_back();
        }
    }
};