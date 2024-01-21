class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        //error done : n agar 1 se kam ho then simply return kar do dp access hi nhi karne do

        std::vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};