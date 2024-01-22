class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size()-1 ; i++)
        {
            if(nums[i] == nums[i+1])
            {
                ans.push_back(nums[i]);
                nums.erase(nums.begin()+i);
                break;
            }
        }
        for(int i = 0 ; i <= nums.size() ; i++)
        {
            if(nums[i] != i+1)
            {
                ans.push_back(i+1);
                break;
            }
        }
        return ans;
    }
};