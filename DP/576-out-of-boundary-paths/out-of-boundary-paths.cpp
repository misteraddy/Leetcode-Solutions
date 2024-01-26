class Solution {
public:
    int mod = 1e9 + 7;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));

        int ans = solve(m, n, maxMove, startRow, startColumn, dp);

        return ans;
    }

    int solve(int m, int n, int maxMove, int i, int j,
              vector<vector<vector<int>>> &dp) {
        if (i >= m || j >= n || i < 0 || j < 0) {
            return 1;
        }

        if (maxMove == 0) {
            return 0;
        }

        if (dp[i][j][maxMove] != -1) {
            return dp[i][j][maxMove];
        }

        int ans = 0;

        int leftmove = solve(m, n, maxMove - 1, i - 1, j, dp);
        ans = (ans + leftmove) % mod;

        int rightmove = solve(m, n, maxMove - 1, i + 1, j, dp);
        ans = (ans + rightmove) % mod;

        int upmove = solve(m, n, maxMove - 1, i, j - 1, dp);
        ans = (ans + upmove) % mod;

        int downmove = solve(m, n, maxMove - 1, i, j + 1, dp);
        ans = (ans + downmove) % mod;

        return dp[i][j][maxMove] = ans;
    }
};
