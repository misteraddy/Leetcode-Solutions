class Solution {
public:
    // Recursive function to solve the problem with memoization
    int solve(int i, int M, bool isAlice, vector<int>& piles, vector<vector<vector<int>>>& dp) {
        int n = piles.size();
        
        // Base case: If the current index is beyond the array size, return 0
        if (i >= n) {
            return 0;
        }

        // Memoization: If the result for this state is already computed, return it
        if (dp[i][M][isAlice] != -1) {
            return dp[i][M][isAlice];
        }

        // Initialize the answer variable based on whether it's Alice's or Bob's turn
        int ans = isAlice ? -1 : INT_MAX;

        int stones = 0;

        // Iterate through all possible values of X (number of piles to take)
        for (int X = 1; X <= min(n - i, 2 * M); X++) {
            stones += piles[i + X - 1];

            // Recursively calculate the result for the next state
            if (isAlice) {
                ans = max(ans, stones + solve(i + X, max(M, X), !isAlice, piles, dp));
            } else {
                ans = min(ans, solve(i + X, max(M, X), !isAlice, piles, dp));
            }
        }

        // Memoize the result and return it
        return dp[i][M][isAlice] = ans;
    }

    // Main function to initiate the recursive solution
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        // Initialize a 3D DP array with memoization
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        
        // Start the recursive solution with initial parameters
        return solve(0, 1, 1, piles, dp);
    }
};