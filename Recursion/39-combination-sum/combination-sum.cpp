class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;  // Store the current combination
        
        //always pass the 2d vector in another function 
        //where vectors ko push karna hai .
        
        findCombinations(candidates, ans, temp, 0, 0, target);
        return ans;
    }

    void findCombinations(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp, int start, int sum, int target) {
        if (sum == target) {
            ans.push_back(temp);  // Found a valid combination, add it to the result
            return;
        }

        if (sum > target || start == candidates.size()) {
            return;  // This branch won't lead to a valid combination
        }

        // Include the current candidate and search for combinations
        temp.push_back(candidates[start]);
        findCombinations(candidates, ans, temp, start, sum + candidates[start], target);

        // Exclude the current candidate and search for combinations
        temp.pop_back();
        findCombinations(candidates, ans, temp, start + 1, sum, target);
        
        // here we can see that the start value is incremented by 1.
        //dont decrement start value in the safe condition voh bas check karne k liye hota hai
        //ki next step safe hai yaa nahi usme koi cheez update nhi hoti hai .
    }
};
