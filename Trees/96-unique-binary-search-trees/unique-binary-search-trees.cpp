class Solution {
public:
    vector<vector<int>> dp;

    //do cheez pata chali ek yeh ki member variable ko constructor k through hi initialise
    //kar sakte hai

    //memset k baare mei 

    Solution() : dp(20, vector<int>(20, -1)) {}

    int numTrees(int n) {
        int ans = solve(1, n);
        return ans;
    }

    int solve(int start, int end) {
        if (start >= end) {
            return 1;
        }

        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        int ans = 0;

        for (int k = start; k <= end; k++) {
            ans += solve(start, k - 1) * solve(k + 1, end);
        }

        return dp[start][end] = ans;
    }
};
