class Solution {
public:
    void numFinder(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp, int sum, int start, int target) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;  // Skip duplicates
            }

            if (sum + candidates[i] <= target) {
                temp.push_back(candidates[i]);
                sum = sum + candidates[i];
                numFinder(candidates, ans, temp,sum, i + 1, target);
                
                //backtracking ho raha guys 
                
                sum = sum - candidates[i];
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Sort the candidates to handle duplicates.
        vector<vector<int>> ans;
        vector<int> temp;
        numFinder(candidates, ans, temp, 0, 0, target);
        return ans;
    }
};
