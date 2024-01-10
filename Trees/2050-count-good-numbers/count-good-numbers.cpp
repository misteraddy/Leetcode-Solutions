class Solution {
public:
    int countGoodNumbers(long long n) {
        const int mod = 1e9 + 7;

        int number_prime[] = {2, 3, 5, 7};

        int p = sizeof(number_prime) / sizeof(number_prime[0]);

        int number_even[] = {0, 2, 4, 6, 8};

        int e = sizeof(number_even) / sizeof(number_even[0]);

        long long even = (n + 1) / 2;

        long long odd = n / 2;

        long long even_ans = fast_expo(5, even, mod);

        long long odd_ans = fast_expo(4, odd, mod);

        int ans = (int)((even_ans * odd_ans) % mod);

        return ans;
    }

    long long fast_expo(long long a, long long b, const int mod) {
        long long ans = 1;

        while (b > 0) {
            if (b % 2 == 1) {
                ans = (ans * a) % mod;
            }

            a = (a * a) % mod;
            b /= 2;
        }

        return ans;
    }
};