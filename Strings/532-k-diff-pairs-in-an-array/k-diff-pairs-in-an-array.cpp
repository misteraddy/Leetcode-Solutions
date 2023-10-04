class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int i = 0, j = 1;
        int count = 0;
        
        //here the set should be used for test case 
        // [1,1,1,1,1] k = 0 -> output = 1 but coming 4
        
        set<pair<int, int>> ans;
        sort(nums.begin(), nums.end());
        int size = nums.size();

        while (j < size) {
            int diff = abs(nums[i] - nums[j]);

            if (diff == k) {
                
                //dont forget to use the curly braces to insert
                
                ans.insert({nums[i], nums[j]});
                i++;
                j++;
            } else if (diff < k) {
                j++;
            } else {
                i++;
                if (i == j) {
                    j++;
                }
            }
        }

        count = ans.size();
        return count;
    }
};
